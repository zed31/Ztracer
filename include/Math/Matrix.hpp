#ifndef MATRIX_HPP__
# define MATRIX_HPP__

#include <type_traits>
#include <array>
#include "BaseAlg.hpp"

namespace Math {

template<typename T, std::size_t WIDTH, std::size_t HEIGHT>
class Matrix : public BaseAlg<Matrix<T, WIDTH, HEIGHT>> {
	using Row = std::integral_constant<std::size_t, WIDTH>;
	using Col = std::integral_constant<std::size_t, HEIGHT>;
	using Size = std::integral_constant<std::size_t, WIDTH * HEIGHT>;
public:
	template<typename... Args>
	Matrix(Args&&... args);

	T &operator()(const std::size_t height, const std::size_t width);
	const T &operator()(const std::size_t height, const std::size_t width) const;

	auto row() const { return Row::value; }
	auto col() const { return Col::value; }
	auto size() const { return Size::value; }
private:
	std::array<T, Size::value> data_;
};

} // namespace Math

#endif