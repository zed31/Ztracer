#ifndef POSITION_HPP__
# define POSITION_HPP__

#include "Component.hpp"
#include "Math/Vector3.hpp"

namespace Component {

struct Position : ComponentBase, Math::Vector3<float> {
	static constexpr Index idxPosition = 0;
	Position(float xPos = 0, float yPos = 0, float zPos = 0) 
		: ComponentBase{ idxPosition }, Math::Vector3<float>{ xPos, yPos, zPos } {};
};

} // namespace Component

#endif