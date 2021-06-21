#include "box.hpp"

Box::Box() :
	min_{ 0.0f, 0.0f, 0.0f },
	max_{ 1.0f, 1.0f, 1.0f } {}

Box::Box(glm::vec3 min, glm::vec3 max) :
	min_{ min },
	max_{ max } {}

float Box::area() const {
	return abs(2 * ((max_.x - min_.x) * (max_.y - min_.y) + (max_.x - min_.x) * (max_.y - min_.y) + (max_.z - min_.z) * (max_.y - min_.y)));
}

float Box::volume() const {
	return abs((max_.x - min_.x) * (max_.y - min_.y) * (max_.y - min_.y));
}