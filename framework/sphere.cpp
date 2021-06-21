#include "sphere.hpp"

Sphere::Sphere() :
	mid_{ 0.0f, 0.0f, 0.0f },
	radius_{1.0f} {}

Sphere::Sphere(glm::vec3 mid, float radius) :
	mid_{ mid },
	radius_{ radius } {}