#include "Shapes/SceneObject.hpp"
#include "Components/Position.hpp"
#include <cassert>

int main() {
	constexpr std::size_t sphereTag = 1;
	Entity::SceneObject obj{ sphereTag };
	obj.add_component<Component::Position>();
	auto& base = obj.get_component<Component::Position::idxPosition>();
	auto position = static_cast<Component::Position&>(base);
	assert(position.x == 0.f && position.y == 0.f && position.z == 0.f);
}