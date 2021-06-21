#include "shape.hpp"

Shape::Shape() :
	name_{ "default" },
	color_{0.0f, 0.0f, 0.0f} {}

Shape::Shape(std::string const& name, Color const& color) :
	name_{ name },
	color_{ color } {}

std::string Shape::get_name() const {
	return name_;
}

Color Shape::get_color() const {
	return color_;
}

std::ostream& Shape::print(std::ostream& os) const {
	os  << "Name: " << name_
		<< "\nColor: { " << color_.r << ", " << color_.g << ", " << color_.b
		<< " }\n\n";
	return os;
}

std::ostream& operator << (std::ostream& os, Shape const& s) {
	s.print(os);
	return os;
}

//Shape::~Shape() {}