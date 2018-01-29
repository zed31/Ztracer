#ifndef BASE_ALG_HPP__
#define BASE_ALG_HPP__

namespace Math {

template<typename Derived>
class BaseAlg {
public:
	auto size() const { return derived().size(); }
	auto col() const { return derived().row(); }
	auto row() const { return derived().col(); }
	
	auto& operator()(const std::size_t height, const std::size_t width) { return derived()(height, width); }
	const auto& operator()(const std::size_t height, const std::size_t width) { return derived()(height, width); }
private:
	auto& derived() { return static_cast<Derived&>(*this); };
	auto const& derived() const { return static_cast<Derived const&>(*this); };
};

} // namespace Math

#endif