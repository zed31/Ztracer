#ifndef SUBSTRACTION_HPP__
#define SUBSTRACTION_HPP__

#include "BaseAlg.hpp"

namespace Math {

template<typename Derived1, typename Derived2>
class Substraction : public BaseAlg<Substraction<Derived1, Derived2>> {
public:

	using value_type = typename Math::common_type<Derived1, Derived2>::type;
	using value_col = typename Math::traits<Derived1>::value_col;
	using value_row = typename Math::traits<Derived1>::value_row;

	Substraction(const Derived1 d1, const Derived2 d2) : derived1_{d1}, derived2_{d2} {
		assert_same_type(value_col{}, value_col{});
		assert_same_type(value_row{}, value_row{});
	}

	auto col() const { return derived1_.col(); }
	auto row() const { return derived1_.row(); }
	auto size() const { return derived1_.size(); }

	auto& operator()(const std::size_t x, const std::size_t y) {
		if (x > 0 && derived2_.col() == 1) return derived1_(x, y);
		return derived1_(x, y) - derived2_(x, y);
	}

	const auto& operator()(const std::size_t x, const std::size_t y) const {
		if (x > 0 && derived2_.col() == 1) return derived1_(x, y);
		return derived1_(x, y) - derived2_(x, y);
	}
private:
	
	Derived1 derived1_;
	Derived2 derived2_;
};

} // namespace Math

#endif
