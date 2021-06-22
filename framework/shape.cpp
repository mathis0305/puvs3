#include "shape.hpp"

Shape::Shape() :
	Shape::Shape{ "default", { 0.0f, 0.0f, 0.0f } } {
	std::cout << "default shape  constructor is called: " << name_ << "\n";
}

Shape::Shape(std::string const& name, Color const& color) :
	name_{ name },
	color_{ color } {
	std::cout << "full    shape  constructor is called: " << name_ << "\n";
}

Shape::~Shape() {
	std::cout << "default shape  destructor  is called: " << name_ << "\n";
}

std::string Shape::get_name() const {
	return name_;
}

Color Shape::get_color() const {
	return color_;
}

std::ostream& Shape::print(std::ostream& os) const {
	os  << "Name: " << name_
		<< "\nColor: { " << color_.r << ", " << color_.g << ", " << color_.b
		<< " }\n";
	return os;
}

std::ostream& operator << (std::ostream& os, Shape const& s) {
	s.print(os);
	return os;
}