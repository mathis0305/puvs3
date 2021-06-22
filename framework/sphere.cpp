#include "sphere.hpp"

Sphere::Sphere() :
	Shape::Shape{ "Sphere", { 0.0f, 0.0f, 0.0f } },
	mid_{ 0.0f, 0.0f, 0.0f },
	radius_{1.0f} {
	std::cout << "default sphere constructor is called: " << name_ << "\n";
}

Sphere::Sphere(glm::vec3 const& mid, float radius) :
	Shape::Shape{ "Sphere", { 0.0f, 0.0f, 0.0f } },
	mid_{ mid },
	radius_{ radius } {
	std::cout << "simple  sphere constructor is called: " << name_ << "\n"; 
}

Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius) :
	Shape::Shape{ name, color },
	mid_{ mid },
	radius_{ radius } {
	std::cout << "full    sphere constructor is called: " << name_ << "\n";
}

Sphere::~Sphere() {
	std::cout << "default sphere destructor  is called: " << name_ << "\n";
}

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

HitPoint Sphere::intersect(Ray const& r) const {
	float len_direction = sqrt(pow(r.direction_.x, 2) + pow(r.direction_.y, 2) + pow(r.direction_.z, 2));
	glm::vec3 normalized_direction{ (r.direction_.x / len_direction), (r.direction_.y / len_direction), (r.direction_.z / len_direction) };
	float distance = 0.0f;
	bool is_intersect =  glm::intersectRaySphere(r.origin_, normalized_direction, mid_, radius_ * radius_, distance);
	HitPoint hitpoint{};
	if (is_intersect) {
		hitpoint.is_intersect_ = true;
		hitpoint.distance_ = distance;
		hitpoint.name_ = name_;
		hitpoint.color_ = color_;
		hitpoint.intersection_ = { { (r.origin_.x + distance + r.direction_.x),
								     (r.origin_.y + distance + r.direction_.y),
								     (r.origin_.z + distance + r.direction_.z) },
								      r.direction_
		};
	}
	return hitpoint;
}