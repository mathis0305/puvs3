#ifndef RAY_HPP
#define RAY_HPP

#include <glm/vec3.hpp>

struct Ray {
	glm::vec3 origin_ = { 0.0f, 0.0f, 0.0f };
	glm::vec3 direction_ = { 0.0f, 0.0f, -1.0f };
};

#endif // #ifndef RAY_HPP