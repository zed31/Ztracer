#ifndef FOV_HPP__
# define FOV_HPP__

#include "Component.hpp"

namespace Component {

struct Fov : Component::ComponentBase {
	static constexpr Component::Index idx = 2;
	Fov(float degAngular) : ComponentBase{ idx } {};
	float angular;
};

} // namespace Component

#endif