#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "Catch.hpp"
#include "include/Math/Vector3.hpp"

SCENARIO("vector3 can be initialized") {
	GIVEN("A simple vector3 templated on float") {
		WHEN("Initialized with only one value") {
			Math::Vector3<float> v{ 0 };

			REQUIRE(v.x == 0.f);
			REQUIRE(v.y == 0.f);
			REQUIRE(v.z == 0.f);
		}
		
		WHEN("Initialized with multiples value") {
			Math::Vector3<float> v{ 1.f, 2.f, 3.f };
			
			REQUIRE(v.x == 1.f);
			REQUIRE(v.y == 2.f);
			REQUIRE(v.z == 3.f);
		}
	}
}

SCENARIO("You can do the sum of 2 vectors3") {
	GIVEN("2 vectors with 1 as x,y,z value") {
		Math::Vector3<float> lhs{ 1.f };
		Math::Vector3<float> rhs{ 1.f };
		auto result = lhs + rhs;

		REQUIRE(result.x == 2.f);
		REQUIRE(result.y == 2.f);
		REQUIRE(result.z == 2.f);
	}

	GIVEN("2 vectors with followings values: \n\t{ 1.f, 2.f, -1.f }\n\t{ -1.f, 3.f, -100.f }") {
		Math::Vector3<float> lhs{ 1.f, 2.f, -1.f };
		Math::Vector3<float> rhs{ -1.f, 3.f, -100.f };
		auto result = lhs + rhs;

		REQUIRE(result.x == 0.f);
		REQUIRE(result.y == 5.f);
		REQUIRE(result.z == -101.f);
	}

	GIVEN("1 vector with following value: \n\t{ 1.f, 2.f, -1.f }\nAnd one constant with the following value: 4.f") {
		Math::Vector3<float> lhs{1.f, 2.f, -1.f};
		auto rhs = 4.f;
		auto result = lhs + rhs;

		REQUIRE(result.x == 5.f);
		REQUIRE(result.y == 4.f);
		REQUIRE(result.z == 3.f);
	}
}

SCENARIO("You can multiply a vector by a constant or by another vector") {
	GIVEN("2 vectors with 2.f as x,y,z value") {
		Math::Vector3<float> lhs{ 2.f };
		Math::Vector3<float> rhs{ 2.f };
		auto result = lhs * rhs;

		REQUIRE(result.x == 4.f);
		REQUIRE(result.y == 4.f);
		REQUIRE(result.z == 4.f);
	}

	GIVEN("2 vectors with followings values: \n\t{ 2.f, 1.f, 4.f }\n\t{ 3.f, 2.f, -1.f }") {
		Math::Vector3<float> lhs{ 2.f, 1.f, 4.f };
		Math::Vector3<float> rhs{ 3.f, 2.f, -1.f };
		auto result = lhs * rhs;

		REQUIRE(result.x == 6.f);
		REQUIRE(result.y == 2.f);
		REQUIRE(result.z == -4.f);
	}

	GIVEN("2 vectors with the followings values:\n\t{ 2.f, 1.f, 3.f }\nAnd a constant: 2.f") {
		Math::Vector3<float> lhs{ 2.f, 1.f, 3.f };
		auto constant = 2.f;
		auto result = lhs * constant;

		REQUIRE(result.x == 4.f);
		REQUIRE(result.y == 2.f);
		REQUIRE(result.z == 6.f);
	}
}

SCENARIO("You can subsract a vector with a constant or another vector") {
	GIVEN("2 vectors with 2.f") {
		Math::Vector3<float> lhs{ 2.f };
		Math::Vector3<float> rhs{ 2.f };
		auto result = lhs - rhs;

		REQUIRE(result.x == 0.f);
		REQUIRE(result.y == 0.f);
		REQUIRE(result.z == 0.f);
	}

	GIVEN("2 vectors with followings value:\n\t{1.f, 2.f, 3.f}\n\t{2.f, 3.f, 4.f}") {
		Math::Vector3<float> lhs{ 2.f, 3.f, 4.f };
	}
}