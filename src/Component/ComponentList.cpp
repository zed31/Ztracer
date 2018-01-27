#include "Components/ComponentList.hpp"

namespace Component {

void ComponentList::add_component(ComponentPtr&& component) {
	components_.push_back(std::move(component));
}

} // namespace Component