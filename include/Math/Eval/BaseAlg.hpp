#ifndef BASE_ALG_HPP__
#define BASE_ALG_HPP__

namespace Math {

template<typename Derived>
class BaseAlg {
public:
	auto size() const { return derived().size(); }
	auto col() const { return derived().row(); }
	auto row() const { return derived().col(); }
	
	auto& operator()(const std::size_t x, const std::size_t y) { return derived()(x, y); }
	const auto& operator()(const std::size_t x, const std::size_t y) const { return derived()(x, y); }
private:
	auto& derived() { return static_cast<Derived&>(*this); };
	auto const& derived() const { return static_cast<Derived const&>(*this); };
};

template<typename D1>
void eval(BaseAlg<D1>& out, const BaseAlg<D1>& alg1) {
	auto col = out.col();
	auto row = out.row();
	for (std::size_t i = 0; i < col; ++i) {
		for (std::size_t j = 0; j < row; ++j) {
			out(i, j) = alg1(i, j);
		}
	}
}

} // namespace Math

#endif