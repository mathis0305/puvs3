#ifndef HITPOINT_HPP
#define HITPOINT_HPP

#include <string>
#include "color.hpp"
#include "ray.hpp"

struct HitPoint {
	bool is_intersect_ = false;
	float distance_;
	std::string name_;
	Color color_;
	Ray intersection_;
};

#endif // #ifndef HITPOINT_HPP