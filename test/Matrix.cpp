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

SCENARIO("We can add 2 matrices") {
	GIVEN("2 2x2 float matrices") {
		Math::Matrix<float, 2, 2> m{ 1.f, 1.f, 1.f, 1.f  };
		Math::Matrix<float, 2, 2> m2{ 1.f, 1.f, 1.f, 1.f };

		auto result = m + m2;

		auto col = result.col();
		auto row = result.row();

		REQUIRE(col == 2);
		REQUIRE(row == 2);

		for (std::size_t i = 0; i < row; ++i) {
			for (std::size_t j = 0; j < col; ++j) {
				auto vResult = result(j, i);
				std::cout << vResult << ",";
				REQUIRE(vResult == 2.f);
			}
			std::cout << std::endl;
		}

		REQUIRE(result.col() == 2);
		REQUIRE(result.row() == 2);
		REQUIRE(result.size() == 4);
	}
}

SCENARIO("We can multiply 2 matrices") {
	GIVEN("2 2x2 matrices") {
		Math::Matrix<float, 2, 2> m{ 1.f, 1.f, 1.f, 1.f };
		Math::Matrix<float, 2, 2> m2{ 2.f, 2.f, 2.f, 2.f };
		auto result = m * m2;

		auto col = result.col();
		auto row = result.row();

		for (std::size_t i = 0; i < row; ++i) {
			for (std::size_t j = 0; j < col; ++j) {
				auto vResult = result(j, i);
				std::cout << vResult << ",";
				REQUIRE(vResult == 4.f);
			}
			std::cout << std::endl;
		}
	}
	GIVEN("1 1x2 matrix and 1 2x2 matrix") {
		Math::Matrix<float, 1, 2> m{ 1.f, 1.f };
		Math::Matrix<float, 2, 2> m2{ 2.f, 2.f, 2.f, 2.f };
		
		REQUIRE(m.col() == 2);
		REQUIRE(m.row() == 1);
		REQUIRE(m2.col() == 2);
		REQUIRE(m2.row() == 2);
		
		auto result = m * m2;

		auto col = result.col();
		auto row = result.row();

		for (std::size_t i = 0; i < row; ++i) {
			for (std::size_t j = 0; j < col; ++j) {
				auto vResult = result(j, i);
				std::cout << vResult << ",";
				REQUIRE(vResult == 4.f);
			}
			std::cout << std::endl;
		}
	}
	GIVEN("1 2x3 matrix and 1 3x4 matrix") {
		Math::Matrix<float, 2, 3> m{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f };
		Math::Matrix<float, 3, 4> m2{ 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f, 2.f };
		
		REQUIRE(m.col() == 3);
		REQUIRE(m.row() == 2);
		REQUIRE(m2.col() == 4);
		REQUIRE(m2.row() == 3);

		auto result = m * m2;
		auto col = result.col();
		auto row = result.row();

		for (std::size_t i = 0; i < row; ++i) {
			for (std::size_t j = 0; j < col; ++j) {
				auto vResult = result(j, i);
				std::cout << vResult << ",";
				//REQUIRE(vResult == 4.f);
			}
			std::cout << std::endl;
		}
	}
}
