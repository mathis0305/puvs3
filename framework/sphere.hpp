#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"
#include <glm/vec3.hpp >

class Sphere : public Shape {
public:
	Sphere();
	Sphere(glm::vec3 mid_, float radius_);

private:
	glm::vec3 mid_;
	float radius_;
};

#endif // #ifndef SPHERE_HPP