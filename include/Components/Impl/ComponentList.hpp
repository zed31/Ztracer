#ifndef COMPONENT_LIST_IMPL_HPP__
#define COMPONENT_LIST_IMPL_HPP__

namespace Component {

template<Index idx>
ComponentBase& ComponentList::get_component() {
	auto it = std::find_if(components_.begin(), components_.end(),
						   [=](auto&& ptr) { return ptr->idx == idx; });

	if (it == components_.end()) {
		throw Component::IllegalIndex{ "ComponentList::get_component: Could not find the specified index" };
	}

	return *(it->get());
}

template<Index idx>
void ComponentList::remove_component() {
	components_.erase(std::remove_if(components_.begin(), components_.end(),
									 [=](auto&& ptr) { return ptr->idx == idx; }), components_.end());
}

} // namespace Component

#endif /* COMPONENT_LIST_IMPL_HPP__ */