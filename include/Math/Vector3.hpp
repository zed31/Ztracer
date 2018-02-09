#ifndef VECTOR_3_HPP__
# define VECTOR_3_HPP__

#include <cassert>
#include <type_traits>
#include <math.h>
#include "include/Math/Eval/BaseAlg.hpp"
#include "include/Math/Eval/Traits.hpp"

namespace Math {

template<typename T>
struct Vector3 : BaseAlg<Vector3<T>> {
	using value_type = T;
	using value_col = std::integral_constant<std::size_t, 3>;
	using value_row = std::integral_constant<std::size_t, 1>;
	using value_size = std::integral_constant<std::size_t, 3>;

	Vector3(const T& val) : x{ val }, y{ val }, z{ val } {};
	Vector3(T xVal, T yVal, T zVal) : x{ xVal }, y{ yVal }, z{ zVal } {};

	
	auto normalize() const -> Vector3 {
		assert(
			length != 0 && 
			"Length of a vector must be different than 0 during normalization"
		);
		T invertLength = 1 / length;
		return Vector3<T>{ x * invertLength, y * invertLength, z * invertLength };
	};

	auto col() const { return value_col::value; }
	auto row() const { return value_row::value; }
	auto size() const { return value_size::value; }

	auto& operator()(const std::size_t pX, const std::size_t) {
		assert(pX < 3 && "There are only 3 elements in a Vector3<T>");
		return pX == 0 ? x : pX == 1 ? y : z;
	}

	auto& operator()(const std::size_t pX, const std::size_t) const {
		assert(pX < 3 && "There are only 3 elements in a Vector3<T>");
		return pX == 0 ? x : pX == 1 ? y : z;
	}

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

	auto operator-(const T& rhs) const -> Vector3 {
		return Vector3<T>{ x - rhs, y - rhs, z - rhs };
	};

	auto operator*(const Vector3& rhs) const -> Vector3 { 
		return Vector3<T>{ x * rhs.x, y * rhs.y, z * rhs.z }; 
	};

	auto operator*(const T& rhs) const -> Vector3 {
		return Vector3<T>{ x * rhs, y * rhs, z * rhs };
	};

	T x;
	T y;
	T z;
};

} // namespace Component

#endif
