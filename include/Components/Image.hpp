#ifndef IMAGE_HPP__
# define IMAGE_HPP__

#include "Component.hpp"

namespace Component {

struct Image : ComponentBase {
	static constexpr Index idx = 3;
	Image(unsigned w, unsigned h) : ComponentBase{ idx }, width{ w }, height{ h }, aspectRatio{ 0.f } {
		float widthF = static_cast<float>(width);
		float heightF = static_cast<float>(height);
		aspectRatio = width > height ? widthF / heightF : height > width ? heightF / widthF : 0.f;
	};
	unsigned width, height;
	float aspectRatio;
};

} // namespace Component

#endif