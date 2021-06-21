#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <cmath>
#include <glm/vec3.hpp >

class Shape {
public:
	virtual float area() const = 0;
	virtual float volume() const = 0;
};

#endif // #ifndef SHAPE_HPP