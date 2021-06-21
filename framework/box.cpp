#include "box.hpp"

Box::Box() :
	Shape::Shape{ "Box", { 0.0f, 0.0f, 0.0f } },
	min_{ 0.0f, 0.0f, 0.0f },
	max_{ 1.0f, 1.0f, 1.0f } {}

Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
	Shape::Shape{ "Box", { 0.0f, 0.0f, 0.0f } },
	min_{ min },
	max_{ max } {}

Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max) :
	Shape::Shape{ name, color },
	min_{ min },
	max_{ max } {}

Box::~Box() {}

float Box::area() const {
	return 2 * (abs(max_.x - min_.x) * abs(max_.y - min_.y) + abs(max_.x - min_.x) * abs(max_.z - min_.z) + abs(max_.z - min_.z) * abs(max_.y - min_.y));
}

float Box::volume() const {
	return abs(max_.x - min_.x) * abs(max_.y - min_.y) * abs(max_.z - min_.z);
}

std::ostream& Box::print(std::ostream& os) const {
	Shape::print(os);
	os  << "Min: {" << min_.x << ", " << min_.y << ", " << min_.z
		<< " }\nMax: {" << max_.x << ", " << max_.y << ", " << max_.z
		<< " }\n\n";
	return os;
}