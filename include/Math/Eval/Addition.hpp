#ifndef ADDITION_HPP__
#define ADDITION_HPP__

#include <algorithm>
#include "BaseAlg.hpp"

namespace Math {

template<typename Derived1, typename Derived2>
class Addition : BaseAlg<Addition<Derived1, Derived2>> {
public:
	Addition(const Derived1& d1, const Derived2& d2) : derived1_{ d1 }, derived2_{ d2 } {};

	auto size() const { return std::max(derived1_.size(), derived2_.size()); };
	auto row() const { return std::max(derived1_.row(), derived2_.row()); };
	auto col() const { return std::max(derived1_.col(), derived2_.col()); };

	auto& operator()(const std::size_t height, const std::size_t width) {
		return derived1_(height, width) + derived2_(height, width);
	};

	const auto& operator()(const std::size_t height, const std::size_t width) const {
		return derived1_(height, width) + derived2_(height, width);
	};
private:
	Derived1 derived1_;
	Derived2 derived2_;
};

} // namespace Math

#endif