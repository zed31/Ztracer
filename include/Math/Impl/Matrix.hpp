#ifndef MATRIX_IMPL_HPP__
#define MATRIX_IMPL_HPP__

namespace Math {

template<typename T, std::size_t X, std::size_t Y>
template<typename... Args>
Matrix<T, X, Y>::Matrix(Args&&... args) : data_{ {std::forward<Args>(args)...} } {}

template<typename T, std::size_t X, std::size_t Y>
T& Matrix<T, X, Y>::operator ()(const std::size_t height, const std::size_t width) {
	assert(height * X + width > Size::value && "Index out of range");
	return data_[height * X + width];
}

template<typename T, std::size_t X, std::size_t Y>
const T& Matrix<T, X, Y>::operator ()(const std::size_t height, const std::size_t width) const {
	assert(height * X + width > Size::value && "Index out of range");
	return data_[height * X + width];
}

} // namespace Math

#endif