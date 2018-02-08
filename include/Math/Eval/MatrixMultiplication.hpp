#ifndef MATRIX_MULTIPLICATION_HPP__
#define MATRIX_MULTIPLICATION_HPP__

#include <iostream>
#include <type_traits>
#include "include/Math/Eval/Traits.hpp"


namespace Math {

template<typename T, std::size_t W, std::size_t H> class Matrix;

} // namespace Math

#include "include/Math/Matrix.hpp"
#include "include/Math/Eval/BaseAlg.hpp"

namespace Math {

template<typename Derived1, typename Derived2>
class MatrixMultiplication : public BaseAlg<MatrixMultiplication<Derived1, Derived2>> {
public:
	using common_type = typename Math::common_type<Derived1, Derived2>::type;
	using value_type = common_type;
	using MatrixResult = Matrix<common_type, Derived1::value_row::value, Derived2::value_col::value>;

	MatrixMultiplication(const Derived1& d1, const Derived2& d2) {
		assert(
			d1.col() == d2.row() && 
			"Number of element in a row must be equal to the number of element in the col"
		);
		auto y = d2.col();
		auto r = d1.row();
		for (std::size_t d2Col = 0; d2Col < y; ++d2Col) {
			for (std::size_t d1Row = 0; d1Row < r; ++d1Row) {
				feed_result(d1, d2, d2Col, d1Row);
			}
		}
	};
	
	auto row() const { return result_.row(); }
	auto col() const { return result_.col(); }
	auto size() const { return result_.size(); }

	auto& operator()(const std::size_t x, const std::size_t y) { return result_(x, y); }
	const auto& operator()(const std::size_t x, const std::size_t y) const { return result_(x, y); }
private:
	void feed_result(const Derived1& d1, const Derived2& d2, std::size_t colD2, std::size_t rowD1) {
		for (std::size_t i = 0; i < d1.col(); ++i) {
			result_(rowD1, colD2) += d1(rowD1, i) * d2(i, colD2);
		}
	}
private:
	MatrixResult result_;
};

} // namespace Math

#endif
