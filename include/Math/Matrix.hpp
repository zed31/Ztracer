#ifndef MATRIX_HPP__
# define MATRIX_HPP__

#include <type_traits>
#include <array>
#include <algorithm>
#include "include/Math/Eval/Addition.hpp"
#include "include/Math/Eval/Substraction.hpp"
#include "include/Math/Eval/Multiplication.hpp"

namespace Math {

template<typename Derived1, typename Derived2> class MatrixMultiplication;

} // namespace Math

#include "include/Math/Eval/MatrixMultiplication.hpp"
#include "include/Math/Eval/BaseAlg.hpp"

namespace Math {

template<typename T, std::size_t HEIGHT, std::size_t WIDTH>
class Matrix : public BaseAlg<Matrix<T, HEIGHT, WIDTH>> {
public:
	using value_col = std::integral_constant<std::size_t, WIDTH>;
	using value_row = std::integral_constant<std::size_t, HEIGHT>;
	using value_size = std::integral_constant<std::size_t, WIDTH * HEIGHT>;
	using value_type = T;

	Matrix() : data_{} {}

	Matrix(std::initializer_list<T> init) {
		assert(
			init.size() == value_size::value && 
			"Size in the brace MUST be the same as the template argument"
		);
		auto it = init.begin();
		for (std::size_t i = 0; i < row(); ++i) {
			for (std::size_t j = 0; j < col(); ++j) {
				data_[i * value_col::value + j] = *it;
				++it;
			}
		}
	}

	template<typename Callable> void for_each(Callable&& c) {
		for (std::size_t i = 0; i < row(); ++i)
			for (std::size_t j = 0; j < col(); ++j)
				c(data_[i * value_col::value + j]);
	}
		
	auto& operator()(const std::size_t x, const std::size_t y) {
		assert(y * value_row::value + x < value_size::value && "Index out of range");
		return data_[y * value_row::value + x];
	};

	auto& operator()(const std::size_t x, const std::size_t y) const {
		assert(y * value_row::value + x < value_size::value && "Index out of range");
		return data_[y * value_row::value + x];
	};

	auto row() const { return value_row::value; }
	auto col() const { return value_col::value; }
	auto size() const { return value_size::value; }
private:
	std::array<value_type, value_size::value> data_;
};

template<typename D1, typename D2>
auto operator+(const BaseAlg<D1>& lhs, const BaseAlg<D2>& rhs) {
	return Addition<D1, D2>{ lhs.derived(), rhs.derived() }; 
}

template<typename D1, typename D2>
auto operator-(const BaseAlg<D1>& lhs, const BaseAlg<D2>& rhs) { 
	return Substraction<D1, D2>{ lhs.derived(), rhs.derived() }; 
}

template<typename D1, typename D2>
auto operator*(const BaseAlg<D1>& lhs, const BaseAlg<D2>& rhs) {
	return MatrixMultiplication<D1, D2>{ lhs.derived(), rhs.derived() };
}

template<typename D1, typename D2>
auto operator%(const BaseAlg<D1>& lhs, const BaseAlg<D2>& rhs) {
	return Multiplication<D1, D2>{ lhs.derived(), rhs.derived() };
}

} // namespace Math

#endif
