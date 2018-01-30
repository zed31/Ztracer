#include "Catch.hpp"
#include <iostream>
#include "include/Math/Matrix.hpp"

SCENARIO("We can instanciate a simple matrix") {
	WHEN("Matrix is float 3x3 matrix") {
		Math::Matrix<float, 3, 3> m{};
		REQUIRE(m.col() == m.row());
		REQUIRE(m.size() == 9);
		REQUIRE(m.row() == 3);
	}
}

SCENARIO("We can add 2 matrix") {
	GIVEN("2 2x2 float matrix") {
		Math::Matrix<float, 2, 2> m{ 1.f, 1.f, 1.f, 1.f  };
		Math::Matrix<float, 2, 2> m2{ 1.f, 1.f, 1.f, 1.f };
		auto result = m + m2;

		auto col = result.col();
		auto row = result.row();

		for (std::size_t i = 0; i < row; ++i) {
			for (std::size_t j = 0; j < col; ++j) {
				std::cout << result(j, i) << ",";
			}
			std::cout << std::endl;
		}

		REQUIRE(result.col() == 2);
		REQUIRE(result.row() == 2);
		REQUIRE(result.size() == 4);
	}
}