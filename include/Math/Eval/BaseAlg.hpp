#ifndef BASE_ALG_HPP__
#define BASE_ALG_HPP__

#include <iostream>
#include "include/Math/Eval/Traits.hpp"

namespace Math {


template<typename Derived>
class BaseAlg {
public:
	using value_type = typename Math::traits<Derived>::type;
	using value_col = typename Math::traits<Derived>::value_col;
	using value_row = typename Math::traits<Derived>::value_row;

	BaseAlg() = default;
	BaseAlg(const BaseAlg& m) {
		eval(*this, m);
	}

	auto size() const { return derived().size(); }
	auto col() const { return derived().col(); }
	auto row() const { return derived().row(); }
	

	auto& derived() { return static_cast<Derived&>(*this); };
	auto& derived() const { return static_cast<const Derived&>(*this); };

	decltype(auto) operator()(const std::size_t x, const std::size_t y) 
	{ return derived()(x, y); }
	decltype(auto) operator()(const std::size_t x, const std::size_t y) const
	{ return derived()(x, y); }
};

template<typename D1>
void eval(BaseAlg<D1>& out, const BaseAlg<D1>& alg1) {
	auto col = out.col();
	auto row = out.row();
	for (std::size_t i = 0; i < row; ++i) {
		for (std::size_t j = 0; j < col; ++j) {
			out(j, i) = alg1(j, i);
		}
	}
}

} // namespace Math

#endif
