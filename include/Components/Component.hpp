#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

namespace Component {

using Index = std::size_t;

struct ComponentBase {
	ComponentBase(Index i) : idx{ i } {}
	Index idx;
};

} // namespace Component

#endif