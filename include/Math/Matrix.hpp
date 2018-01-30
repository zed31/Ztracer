#ifndef MATRIX_HPP__
# define MATRIX_HPP__

#include <type_traits>
#include <array>
#include "include/Math/Eval/Addition.hpp"
#include "include/Math/Eval/Substraction.hpp"
#include "include/Math/Eval/Multiplication.hpp"
#include "include/Math/Eval/BaseAlg.hpp"

namespace Math {

template<typename T, std::size_t WIDTH, std::size_t HEIGHT>
class Matrix : public BaseAlg<Matrix<T, WIDTH, HEIGHT>> {

	using Row = std::integral_constant<std::size_t, HEIGHT>;
	using Col = std::integral_constant<std::size_t, WIDTH>;
	using Size = std::integral_constant<std::size_t, WIDTH * HEIGHT>;

public:
	Matrix() = default;

	Matrix(std::initializer_list<T> init) {
		assert(init.size() == Size::value && "Size in the brace MUST be the same as the template argument");
		auto it = init.begin();
		for (std::size_t i = 0; i < row(); ++i) {
			for (std::size_t j = 0; j < col(); ++j) {
				data_[i * WIDTH + j] = *it;
				++it;
			}
		}
	}
	
	template<typename D>
	Matrix(const BaseAlg<D>& alg) {
		assert(alg.row() == row() && alg.col() == col() && "Error, both column and row number must be the same");
		eval(*this, alg);
	}
	
	auto& operator()(const std::size_t x, const std::size_t y) {
		assert(y * WIDTH + x < Size::value && "Index out of range");
		return data_[y * WIDTH + x];
	};

	const T& operator()(const std::size_t x, const std::size_t y) const {
		assert(y * WIDTH + x < Size::value && "Index out of range");
		return data_[y * WIDTH + x];
	};

	auto row() const { return Row::value; }
	auto col() const { return Col::value; }
	auto size() const { return Size::value; }
private:
	std::array<T, Size::value> data_;
};

template<typename T, std::size_t W, std::size_t H>
auto operator+(const Matrix<T, W, H>& lhs, const Matrix<T, W, H>& rhs) {
	return Addition<Matrix<T, W, H>, Matrix<T, W, H>>{ lhs, rhs }; 
}

template<typename T, std::size_t W, std::size_t H>
auto operator-(const Matrix<T, W, H>& lhs, const Matrix<T, W, H>& rhs) { 
	return Substraction<Matrix<T, W, H>, Matrix<T, W, H>>{ lhs, rhs }; 
}

template<typename T, std::size_t W, std::size_t H>
auto operator*(const Matrix<T, W, H>& lhs, const Matrix<T, W, H>& rhs) {
	return Matrix<T, W, H>{ Multiplication<Matrix<T, W, H>, Matrix<T, W, H>>{ lhs, rhs } };
}

} // namespace Math

#endif