#ifndef __SCENE_OBJECT_HPP__
# define __SCENE_OBJECT_HPP__

#include "Components/ComponentList.hpp"

namespace Entity {

using Tag = std::size_t;

class SceneObject {
public:
	SceneObject(Tag tag);
	SceneObject(const SceneObject&) = delete;
	SceneObject &operator=(const SceneObject&) = delete;
	SceneObject(SceneObject&&) = default;

	template<typename Comp, typename... Args>
	void add_component(Args&&... args);

	template<Component::Index idx>
	Component::ComponentBase& get_component();
private:
	Component::ComponentList components_;
	Tag tag_;
};

} // namespace Entity

#include "Impl/SceneObject.hpp"

#endif