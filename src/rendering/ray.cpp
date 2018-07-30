#include "rendering/ray.hpp"

namespace rendering {

ray::ray(const ray::vector_ray& o, const ray::vector_ray& d)
    : m_origin{ o }, m_direction{ d } {}

const ray::vector_ray& ray::origin() const {
    return m_origin;
}

const ray::vector_ray& ray::direction() const {
    return m_direction;
}

ray::vector_ray ray::trace_at(float point) const {
    return m_origin + point * m_direction;
}

} //namespace rendering