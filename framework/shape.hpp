#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cmath>
#include <glm/vec3.hpp>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "color.hpp"
#include "hitpoint.hpp"


class Shape {
public:
	Shape();
	Shape(std::string const& name, Color const& color);
	virtual ~Shape();

	std::string get_name() const;
	Color get_color() const;

	virtual float area() const = 0;
	virtual float volume() const = 0;
	virtual std::ostream& print(std::ostream& os) const;

protected:
	std::string name_;
	Color color_;
};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // #ifndef SHAPE_HPP