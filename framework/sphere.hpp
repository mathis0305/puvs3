#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"

class Sphere : public Shape {
public:
	Sphere();
	Sphere(glm::vec3 mid_, float radius_);

	float area() const override;
	float volume() const override;

private:
	glm::vec3 mid_;
	float radius_;
};

#endif // #ifndef SPHERE_HPP