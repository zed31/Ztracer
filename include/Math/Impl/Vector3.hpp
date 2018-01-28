#ifndef VECTOR3_IMPL_HPP__
#define VECTOR3_IMPL_HPP__

#include <cmath>

namespace Math {

template<typename T>
Vector3<T>::Vector3(const T& val) : x{ val }, y{ val }, z{ val } {}

template<typename T>
Vector3<T>::Vector3(T xVal, T yVal, T zVal) 
	: x{ xVal }, y{ yVal }, z{ zVal } {
};

template<typename T>
T Vector3<T>::length() const {
	return std::sqrt(dot_product(*this));
}

template<typename T>
Vector3<T> Vector3<T>::normalize() const {
	assert(length != 0 && "Length of a vector must be different than 0 during normalization");
	T invertLength = 1 / length;
	return Vector3<T>{ x * invertLength, y * invertLength, z * invertLength };
}

template<typename T>
T Vector3<T>::dot_product(const Vector3<T>& v) const {
	return Vector3<T>{ x * v.x, y * v.y, z * v.z };
}

template<typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T>& v) const {
	return Vector3<T>{
		y * v.z - z * v.y,
		z * v.x - x * v.z,
		x * v.y - y * v.x
	};
}

template<typename T>
Vector3<T> operator+(const Vector3<T>& lhs, const Vector3<T>& rhs) {
	return Vector3<T>{
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	};
}

template<typename T>
Vector3<T> operator-(const Vector3<T>& lhs, const Vector3<T>& rhs) {
	return Vector3<T>{
		lhs.x - rhs.x,
		lhs.y - rhs.y,
		lhs.z - rhs.z
	};
}

template<typename T>
Vector3<T> operator*(const Vector3<T>& lhs, const Vector3<T>& rhs) {
	return Vector3<T>{
		lhs.x * rhs.x,
		lhs.y * rhs.y,
		lhs.z * rhs.z
	};
}

} // namespace Math

#endif //VECTOR3_IMPL_HPP__