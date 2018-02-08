#ifndef TRAITS_HPP__
#define TRAITS_HPP__

#include <type_traits>

namespace Math {

template<typename T> struct traits;

template<
	template<class, std::size_t, std::size_t> class M, 
	typename T, 
	std::size_t H, 
	std::size_t W
> struct traits<M<T, H, W>> {
	using type = T;
	using value_col = std::integral_constant<std::size_t, W>;
	using value_row = std::integral_constant<std::size_t, H>;
};

template<typename D1, typename D2> struct common_type {
	using type = std::common_type_t<typename D1::value_type, typename D2::value_type>;
};

template<
	template<class, class> class Eval,
	class D1,
	class D2
> struct traits<Eval<D1, D2>> {
	using type = typename common_type<D1, D2>::type;
	using value_col = typename traits<D1>::value_col;
	using value_row = typename traits<D2>::value_row;
};

template<template<class> typename V, typename T> struct traits<V<T>> {
	using type = T;
	using value_col = std::integral_constant<std::size_t, 1>;
	using value_row = std::integral_constant<std::size_t, 3>;
};

template<typename T> struct type_wrapper {};

template<class T1, class T2> inline void assert_same_type(T1, T2) {
	type_wrapper<T1>{} = type_wrapper<T2>{};
}

} // namespace Math

#endif //TRAITS_HPP__
