#include "include/Shapes/SceneObject.hpp"
#include "include/Components/Position.hpp"
#include <cassert>
#include <iostream>

int main() {
	constexpr std::size_t sphereTag = 1;
	Entity::SceneObject obj{ sphereTag };
	obj.add_component<Component::Position>();
	auto& base = obj.get_component<Component::Position::idx>();
	auto position = static_cast<Component::Position&>(base);
	std::cout << "eclair a la vaniiiiiiiiille" << std::endl;
	assert(position.x == 0.f && position.y == 0.f && position.z == 0.f);
}