#ifndef RAY_HPP__
# define RAY_HPP__

#include <lib/glm/glm.hpp>

namespace rendering {

class ray {
public:
    using vector_ray = glm::vec3;

    ray() = default;
    ray(const vector_ray& origin, const vector_ray& direction);

    const vector_ray& origin() const;
    const vector_ray& direction() const;
    vector_ray trace_at(float point) const;
private:
    vector_ray m_origin;
    vector_ray m_direction;
};

}

#endif