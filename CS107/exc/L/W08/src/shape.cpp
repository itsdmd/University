#include "shape.h"

#include <cmath>
#include <iostream>

using std::cout;
using std::to_string;

/// ------------------------------------------------------------------------ ///
///                                 ShapeList                                ///
/// ------------------------------------------------------------------------ ///
ShapeList::ShapeList() {
	this->m_shapes.clear();
}

ShapeList::~ShapeList() {
	for (auto shape : this->m_shapes)
		delete shape;
}

void ShapeList::add(Shape *shape) {
	this->m_shapes.push_back(shape);
}

void ShapeList::print() const {
	for (auto shape : this->m_shapes) {
		cout << shape->print(true) << "\n";
	}
}

/// ------------------------------------------------------------------------ ///
///                                 Rectangle                                ///
/// ------------------------------------------------------------------------ ///
/* #region   */
Rectangle::Rectangle(float width, float height) {
	this->m_width = width;
	this->m_height = height;
}

double Rectangle::area() const {
	return (double)(this->m_width * this->m_height);
}

double Rectangle::perimeter() const {
	return (double)(2 * (this->m_width + this->m_height));
}

string Rectangle::print(bool withCalculation) const {
	string res = "Rectangle: Width=" + to_string(this->m_width) + ", Height=" + to_string(this->m_height);

	if (withCalculation) {
		res += " => Area=" + to_string(this->area()) + ", Perimeter=" + to_string(this->perimeter());
	}

	res += "\n";


	return res;
}

/* #endregion */


/// ------------------------------------------------------------------------ ///
///                                 Triangle                                 ///
/// ------------------------------------------------------------------------ ///
/* #region   */
Triangle::Triangle(float a, float b, float c) {
	this->m_a = a;
	this->m_b = b;
	this->m_c = c;
}

double Triangle::area() const {
	double p = (this->perimeter() / 2);
	return sqrt(p * (p - this->m_a) * (p - this->m_b) * (p - this->m_c));
}

double Triangle::perimeter() const {
	return (double)(this->m_a + this->m_b + this->m_c);
}

string Triangle::print(bool withCalculation) const {
	string res = "Triangle: A=" + to_string(this->m_a) + ", B=" + to_string(this->m_b) + ", C=" + to_string(this->m_c);

	if (withCalculation) {
		res += " => Area=" + to_string(this->area()) + ", Perimeter=" + to_string(this->perimeter());
	}

	res += "\n";


	return res;
}

/* #endregion */


/// ------------------------------------------------------------------------ ///
///                                  Circle                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */
Circle::Circle(float radius) {
	this->m_radius = radius;
}

double Circle::area() const {
	return (double)(M_PI * pow(this->m_radius, 2));
}

double Circle::perimeter() const {
	return (double)(2 * M_PI * this->m_radius);
}

string Circle::print(bool withCalculation) const {
	string res = "Circle: Radius=" + to_string(this->m_radius);

	if (withCalculation) {
		res += " => Area=" + to_string(this->area()) + ", Perimeter=" + to_string(this->perimeter());
	}

	res += "\n";


	return res;
}

/* #endregion */