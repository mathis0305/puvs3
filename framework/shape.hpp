#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cmath>
#include <glm/vec3.hpp >
#include <string>
#include "color.hpp"

class Shape {
public:
	Shape();
	Shape(std::string const& name, Color const& color);
	//~Shape();

	std::string get_name() const;
	Color get_color() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;

protected:
	std::string name_;
	Color color_;
};

#endif // #ifndef SHAPE_HPP