#ifndef ADDITION_HPP__
#define ADDITION_HPP__

#include <type_traits>
#include <algorithm>
#include "include/Math/Eval/Traits.hpp"
#include "include/Math/Eval/BaseAlg.hpp"

namespace Math {

template<typename Derived1, typename Derived2>
class Addition : BaseAlg<Addition<Derived1, Derived2>> {
public:
	using value_row = typename Math::traits<Derived1>::value_row;
	using value_col = typename Math::traits<Derived1>::value_col;
	using value_type = typename Math::common_type<Derived1, Derived2>::type;

	Addition(const Derived1& d1, const Derived2& d2) : derived1_{ d1 }, derived2_{ d2 } {
		assert_same_type(
			typename Math::traits<Derived1>::value_row{}, 
			typename Math::traits<Derived2>::value_row{}
		);
		assert_same_type(
			typename Math::traits<Derived2>::value_col{}, 
			typename Math::traits<Derived1>::value_col{}
		);
	};

	auto size() const { return derived1_.size(); };
	auto row() const { return derived1_.row(); };
	auto col() const { return derived1_.col(); };

	decltype(auto) operator()(const std::size_t x, const std::size_t y) {
		return derived1_(x, y) + derived2_(x, y);
	};

	decltype(auto) operator()(const std::size_t x, const std::size_t y) const {
		return derived1_(x, y) + derived2_(x, y);
	}
private:
	Derived1 derived1_;
	Derived2 derived2_;
};

} // namespace Math

#endif
