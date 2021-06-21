#include "box.hpp"

Box::Box() :
	min_{ 0.0f, 0.0f, 0.0f },
	max_{ 1.0f, 1.0f, 1.0f } {}

Box::Box(glm::vec3 min, glm::vec3 max) :
	min_{ min },
	max_{ max } {}

float Box::area() const {
	return 2 * (abs(max_.x - min_.x) * abs(max_.y - min_.y) + abs(max_.x - min_.x) * abs(max_.z - min_.z) + abs(max_.z - min_.z) * abs(max_.y - min_.y));
}

float Box::volume() const {
	return abs(max_.x - min_.x) * abs(max_.y - min_.y) * abs(max_.z - min_.z);
}