#include "Catch.hpp"
#include "include/Math/Matrix.hpp"

SCENARIO("We can instanciate a simple matrix") {
	WHEN("Matrix is float 3x3 matrix") {
		Math::Matrix<float, 3, 3> m{};
		REQUIRE(m.col() == m.row());
		REQUIRE(m.size() == 9);
		REQUIRE(m.row() == 3);
	}
}