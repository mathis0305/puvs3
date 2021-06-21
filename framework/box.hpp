#ifndef BOX_HPP
#define BOX_HPP

#include "shape.hpp"

class Box : public Shape {
public:
	Box();
	Box(glm::vec3 const& min, glm::vec3 const& max);
	Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);
	//~Box() override;

	float area() const override;
	float volume() const override;

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif // #ifndef BOX_HPP