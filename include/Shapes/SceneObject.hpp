#ifndef __SCENE_OBJECT_HPP__
# define __SCENE_OBJECT_HPP__

#include "Components/ComponentList.hpp"

namespace Scene {

class SceneObject {
public:
	SceneObject() = default;
	SceneObject(const SceneObject&) = delete;
	SceneObject &operator=(const SceneObject&) = delete;
	SceneObject(SceneObject&&) = default;

	template<typename Comp, typename... Args>
	void add_component(Args&&... args);

	template<Component::Index idx>
	Component::ComponentBase& get_component();
private:
	Component::ComponentList components_;
};

} // namespace Scene

#include "Impl/SceneObject.hpp"

#endif