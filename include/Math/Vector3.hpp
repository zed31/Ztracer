#ifndef VECTOR_3_HPP__
# define VECTOR_3_HPP__

namespace Math {

template<typename T>
struct Vector3 {
	Vector3(T xVal, T yVal, T zVal) : x{ xVal }, y{ yVal }, z{ zVal } {};
	T x, y, z;
};

} // namespace Component

#endif