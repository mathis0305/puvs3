#include "box.hpp"

Box::Box() :
	min_{ 0.0f, 0.0f, 0.0f },
	max_{ 1.0f, 1.0f, 1.0f } {}

Box::Box(glm::vec3 min, glm::vec3 max) :
	min_{ min },
	max_{ max } {}