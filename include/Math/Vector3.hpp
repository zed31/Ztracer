#ifndef VECTOR_3_HPP__
# define VECTOR_3_HPP__

namespace Math {

template<typename T>
struct Vector3 {
	Vector3(const T& val);
	Vector3(T xVal, T yVal, T zVal);
	T dot_product(const Vector3<T>& v) const;
	T length() const;
	Vector3 normalize() const;
	Vector3 cross(const Vector3<T>& v) const;

	const T x;
	const T y;
	const T z;
};

template<typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs);

template<typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs);

template<typename T>
Vector3<T> operator*(const Vector3<T>& lhs, const Vector3<T>& rhs);

} // namespace Component

#include "Impl/Vector3.hpp"

#endif