#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include "ray.hpp"



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
	Box b2{ "b1", {0.0f, 0.0f, 0.0f}, {4.5f, 8.1f, -3.02f} ,{8.2f, 14.01f, 1.1f} };

	REQUIRE(b1.area() == Approx(6.0f));
	REQUIRE(b2.area() == Approx(122.92f));

	REQUIRE(b1.volume() == Approx(1.0f));
	REQUIRE(b2.volume() == Approx(90.092f));
}

TEST_CASE("vererbung" "[vererbung]") {
	Box b1{};
	Sphere s1{};

	REQUIRE(b1.get_name() == "Box");
	REQUIRE(s1.get_name() == "Sphere");

	REQUIRE(b1.get_color().b == 0.0f);
	REQUIRE(s1.get_color().g == 0.0f);
}

TEST_CASE("intersect_ray_sphere", "[intersect]") {
	// Ray
	glm::vec3 ray_origin{ 0.0f, 0.0f, 0.0f };
	// ray direction has to be normalized !
	// you can use :
	// v = glm :: normalize ( some_vector )
	glm::vec3 ray_direction{ 0.0f, 0.0f, 1.0f };
	// Sphere
	glm::vec3 sphere_center{ 0.0f ,0.0f, 5.0f };
	float sphere_radius{ 1.0f };
	float distance = 0.0f;
	auto result = glm::intersectRaySphere(
		ray_origin, ray_direction,
		sphere_center,
		sphere_radius * sphere_radius, // squared radius !!!
		distance);
	REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("intersect method", "[intersect_method]") {
	Sphere s1{ {-2.56197, -3.20253, 0.3}, 1.1489 };
	Sphere s2{ {-4.73, 5.67, 1.4}, 2.184 };
	Sphere s3{ {0, 0, -1.84}, 0.4 };

	Ray r1{ {3.09003, 0.74439, 0}, {-3.09, -0.74, -1.84} };
	Ray r2{ {-3.46, -0.5, -0.43}, {5.33, -3.67, 0.43} };
	Ray r3{ {-1.85885, -4.4679, 0}, {-2.42, 6.2, 0} };

	HitPoint h1 = s1.intersect(r1);
	HitPoint h2 = s1.intersect(r2);
	HitPoint h3 = s1.intersect(r3);

	HitPoint h4 = s2.intersect(r1);
	HitPoint h5 = s2.intersect(r2);
	HitPoint h6 = s2.intersect(r3);

	HitPoint h7 = s3.intersect(r1);
	HitPoint h8 = s3.intersect(r2);
	HitPoint h9 = s3.intersect(r3);

	REQUIRE(h1.is_intersect_ == false);
	REQUIRE(h2.is_intersect_ == false);
	REQUIRE(h3.is_intersect_ == true);

	REQUIRE(h4.is_intersect_ == false);
	REQUIRE(h5.is_intersect_ == false);
	REQUIRE(h6.is_intersect_ == true);

	REQUIRE(h7.is_intersect_ == true);
	REQUIRE(h8.is_intersect_ == false);
	REQUIRE(h9.is_intersect_ == false);

	REQUIRE(h3.distance_ == Approx(0.34264f));
	REQUIRE(h6.distance_ == Approx(9.1513f));
	REQUIRE(h7.distance_ == Approx(3.2726f));
	REQUIRE(h9.distance_ == 0.0f);

	REQUIRE(h1.name_ == "");
	REQUIRE(h3.name_ == "Sphere");
	REQUIRE(h6.name_ == "Sphere");
	REQUIRE(h7.name_ == "Sphere");
}

int main(int argc, char *argv[]) {
	Box b1{};
	std::cout << b1;

	Sphere s1{};
	std::cout << s1;
  return Catch::Session().run(argc, argv);
}
