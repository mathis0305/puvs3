#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"

class Box : public Shape {
public:
	Box();
	Box(glm::vec3 min_, glm::vec3 max_);

	float area() const override;
	float volume() const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif // #ifndef BOX_HPP