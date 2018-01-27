#ifndef DIRECTION_HPP__
#define DIRECTION_HPP__

#include "Math/Vector3.hpp"
#include "Component.hpp"

namespace Component {

struct Direction : ComponentBase, Math::Vector3<float> {
	static constexpr Index idxDirection = 1;
	Direction(float xDir, float yDir, float zDir) 
		: ComponentBase{ idxDirection }, Math::Vector3<float>{ xDir, yDir, zDir } {}
};

} // namespace Component

#endif