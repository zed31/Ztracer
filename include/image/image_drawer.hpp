#ifndef IMAGE_DRAWER_HPP__
# define IMAGE_DRAWER_HPP__

#include <vector>
#include <iostream>
#include "color.hpp"

namespace image {

using color_t = color;
using color_container_t = std::vector<color_t>;

template<typename OutputImageWritter> class image_drawer {
public:
    using output_image_t = OutputImageWritter;

    explicit image_drawer(output_image_t&& output_image_stream);
    void insert_on_stream(const color_container_t& colors);
    output_image_t&& get_output_image();
private:
    output_image_t m_output_image_stream;
};

template<typename T> 
image_drawer<T>::image_drawer(output_image_t&& output_image_stream)
    : m_output_image_stream{ std::move(output_image_stream) } {}

template<typename T>
void image_drawer<T>::insert_on_stream(const color_container_t& colors) {
    m_output_image_stream << colors;
}

template<typename T>
typename image_drawer<T>::output_image_t&& image_drawer<T>::get_output_image() {
    return std::move(m_output_image_stream);
}

} //namespace image

#endif //IMAGE_DRAWER_HPP__