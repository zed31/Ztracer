#ifndef COMPONENT_LIST_HPP__
#define COMPONENT_LIST_HPP__

#include <algorithm>
#include <vector>
#include <memory>
#include <optional>
#include <initializer_list>
#include "Component.hpp"
#include "Components/Exception.hpp"

namespace Component {

class ComponentList {
	using ComponentPtr = std::unique_ptr<ComponentBase>;
	using CompVec = std::vector<ComponentPtr>;
public:
	ComponentList() = default;
	ComponentList(const ComponentList&) = delete;
	ComponentList &operator=(const ComponentList&) = delete;
	ComponentList(ComponentList&&) = default;

	void add_component(ComponentPtr&& component);
	template<Index idx>
	void remove_component();
	template<Index idx>
	ComponentBase& get_component();
private:
	CompVec components_;
};

} // namespace Component

#include "Impl/ComponentList.hpp"

#endif