#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "shape.hpp"

class Sphere : public Shape {
public:
	Sphere();
	Sphere(glm::vec3 const& mid, float radius);
	Sphere(std::string const& name, Color const& color, glm::vec3 const& mid, float radius);

	float area() const override;
	float volume() const override;
	std::ostream& print(std::ostream& os) const override;

private:
	glm::vec3 mid_;
	float radius_;
};

#endif // #ifndef SPHERE_HPP