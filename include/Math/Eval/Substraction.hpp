#ifndef SUBSTRACTION_HPP__
#define SUBSTRACTION_HPP__

#include "BaseAlg.hpp"

namespace Math {

template<typename Derived1, typename Derived2>
class Substraction : public BaseAlg<Substraction<Derived1, Derived2>> {
public:
	Substraction(const Derived1 d1, const Derived2 d2) : derived1_{d1}, derived2_{d2} {}

	auto col() const { return std::max(derived1_.col(), derived2_.col()); }
	auto row() const { return std::max(derived1_.row(), derived2_.row()); }
	auto size() const { return std::max(derived1_.size(), derived2_.size()); }

	auto& operator()(const std::size_t height, const std::size_t width) {
		return derived1_(height, width) - derived2_(height, width);
	}

	const auto& operator()(const std::size_t height, const std::size_t width) const {
		return derived1_(height, width) - derived2_(height, width);
	}
private:
	Derived1 derived1_;
	Derived2 derived2_;
};

} // namespace Math

#endif