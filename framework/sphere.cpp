#include "sphere.hpp"

Sphere::Sphere() :
	Shape::Shape{ "Sphere", { 0.0f, 0.0f, 0.0f } },
	mid_{ 0.0f, 0.0f, 0.0f },
	radius_{1.0f} {}

Sphere::Sphere(glm::vec3 const& mid, float radius) :
	Shape::Shape{ "Sphere", { 0.0f, 0.0f, 0.0f } },
	mid_{ mid },
	radius_{ radius } {}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius) :
	Shape::Shape{ name, color },
	mid_{ mid },
	radius_{ radius } {}

Sphere::~Sphere() {}

float Sphere::area() const {
	return 8.0f * acos(0.0f) * pow(radius_, 2);
}

float Sphere::volume() const {
	return (4.0f / 3.0f) * (2.0f * acos(0.0f)) * pow(radius_, 3);
}

std::ostream& Sphere::print(std::ostream& os) const {
	Shape::print(os);
	os 	<< "Center: { " << mid_.x << ", " << mid_.y << ", " << mid_.z
		<< " }\nRadius: " << radius_
		<< "\n\n";
	return os;
}