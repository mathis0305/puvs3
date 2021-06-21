#include "sphere.hpp"

Sphere::Sphere() :
	mid_{ 0.0f, 0.0f, 0.0f },
	radius_{1.0f} {}

Sphere::Sphere(glm::vec3 mid, float radius) :
	mid_{ mid },
	radius_{ radius } {}

float Sphere::area() const {
	return 8.0 * acos(0.0) * pow(radius_, 2);
}

float Sphere::volume() const {
	return (4 / 3) * 2.0 * acos(0.0) * pow(radius_, 3);
}