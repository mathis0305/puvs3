#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"



TEST_CASE("area and volume of sphere" "[area_volume_sphere]") {
	Sphere s1{};
	Sphere s2{ {4.5f, 8.1f, -3.02f}, 27.39f };

	REQUIRE(s1.area() == Approx(12.56637061f));
	REQUIRE(s2.area() == Approx(9427.443287f));

	REQUIRE(s1.volume() == Approx(4.188790204f));
	REQUIRE(s2.volume() == Approx(86072.55721f));
}

TEST_CASE("area and volume of box" "[area_volume_box]") {
	Box b1{};
	Box b2{ {4.5f, 8.1f, -3.02f} ,{8.2f, 14.01f, 1.1f} };

	REQUIRE(b1.area() == Approx(6.0f));
	REQUIRE(b2.area() == Approx(122.92f));

	REQUIRE(b1.volume() == Approx(1.0f));
	REQUIRE(b2.volume() == Approx(90.092f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
