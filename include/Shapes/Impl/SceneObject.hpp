#ifndef SCENE_OBJECT_IMPL_HPP__
#define SCENE_OBJECT_IMPL_HPP__

namespace Scene {

template<typename T, typename... Args>
void SceneObject::add_component(Args&&... args) {
	components_.add_component(std::make_unique<T>(std::forward<Args>(args)...));
}

template<Component::Index idx>
Component::ComponentBase& SceneObject::get_component() {
	return components_.get_component<idx>();
}

} // namespace Scene

#endif