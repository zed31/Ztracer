#ifndef VECTOR_3_HPP__
# define VECTOR_3_HPP__

namespace Math {

#include <cmath>

template<typename T>
struct Vector3 {
	Vector3(const T& val) : x{ val }, y{ val }, z{ val } {};
	Vector3(T xVal, T yVal, T zVal) : x{ xVal }, y{ yVal }, z{ zVal } {};

	
	auto normalize() const -> Vector3 {
		assert(length != 0 && "Length of a vector must be different than 0 during normalization");
		T invertLength = 1 / length;
		return Vector3<T>{ x * invertLength, y * invertLength, z * invertLength };
	};

	auto cross(const Vector3& v) const -> Vector3 { 
		return Vector3<T>{ y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x }; 
	};

	auto dot_product(const Vector3& v) const -> Vector3 { 
		return Vector3<T>{ x * v.x, y * v.y, z * v.z }; 
	};

	auto length() const -> T { 
		return std::sqrt(dot_product(*this)); 
	};

	auto operator+(const Vector3& rhs) const -> Vector3 { 
		return Vector3<T>{ x + rhs.x, y + rhs.y, z + rhs.z }; 
	};

	auto operator+(const T& rhs) const -> Vector3 {
		return Vector3<T>{ x + rhs, y + rhs, z + rhs };
	}

	auto operator-(const Vector3& rhs) const -> Vector3 {
		return Vector3<T>{ x - rhs.x, y - rhs.y, z - rhs.z }; 
	};

	auto operator-(const T& value) const -> Vector3 {
		return Vector3<T>{ x - value, y - value, z - value };
	};

	auto operator*(const Vector3& rhs) const -> Vector3 { 
		return Vector3<T>{ x * rhs.x, y * rhs.y, z * rhs.z }; 
	};

	auto operator*(const T& rhs) const -> Vector3 {
		return Vector3<T>{ x * rhs, y * rhs, z * rhs };
	};

	const T x;
	const T y;
	const T z;
};

} // namespace Component

#endif