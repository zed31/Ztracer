#ifndef TRAITS_HPP__
#define TRAITS_HPP__

#include <type_traits>

namespace Math {

template<typename T> struct traits;

template<
	template<class, std::size_t, std::size_t> class M, 
	typename T, 
	std::size_t W, 
	std::size_t H
> struct traits<M<T, W, H>> {
	using type = T;
	using width = std::integral_constant<std::size_t, W>;
	using height = std::integral_constant<std::size_t, H>;
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
};

template<template<class> typename V, typename T> struct traits<V<T>> {
	using type = T;
};

} // namespace Math

#endif //TRAITS_HPP__
