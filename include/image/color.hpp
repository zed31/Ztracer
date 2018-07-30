#ifndef COLOR_HPP__
# define COLOR_HPP__

namespace image {

class color {
public:
    using rgba_t = unsigned char;
    rgba_t red;
    rgba_t green;
    rgba_t blue;
    rgba_t alpha;
};

} //namespace image

#endif //COLOR_HPP__