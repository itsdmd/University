#include "shape.h"

#include <iostream>

using std::cout;

/// ------------------------------------------------------------------------ ///
///                                 Rectangle                                ///
/// ------------------------------------------------------------------------ ///
Rectangle::Rectangle() {
	this->m_attr.resize(2);
}

Rectangle::Rectangle(const float x_top, const float y_top, const float x_low, const float y_low) {
	this->m_attr.push_back({ x_top, y_top });
	this->m_attr.push_back({ x_low, y_low });
}

Rectangle::~Rectangle() {
	this->m_attr.clear();
}

void Rectangle::printShape() const {
	cout << "Rectangle, [(" << this->m_attr[0][0] << ";" << this->m_attr[0][1] << "), (" << this->m_attr[1][0] << ";" << this->m_attr[1][1] << ")]";
}


/// ------------------------------------------------------------------------ ///
///                                 Triangle                                 ///
/// ------------------------------------------------------------------------ ///
Triangle::Triangle() {
	this->m_attr.resize(3);
}

Triangle::Triangle(const float x_1, const float y_1, const float x_2, const float y_2, const float x_3, const float y_3) {
	this->m_attr.push_back({ x_1, y_1 });
	this->m_attr.push_back({ x_2, y_2 });
	this->m_attr.push_back({ x_3, y_3 });
}

Triangle::~Triangle() {
	this->m_attr.clear();
}

void Triangle::printShape() const {
	cout << "Triangle, [(" << this->m_attr[0][0] << ";" << this->m_attr[0][1] << "), (" << this->m_attr[1][0] << ";" << this->m_attr[1][1] << "), (" << this->m_attr[2][0] << ";" << this->m_attr[2][1] << ")]";
}


/// ------------------------------------------------------------------------ ///
///                                  Circle                                  ///
/// ------------------------------------------------------------------------ ///
Circle::Circle() {
	this->m_attr.resize(2);
}

Circle::Circle(const float x_center, const float y_center, const float radius) {
	this->m_attr.push_back({ x_center, y_center });
	this->m_attr.push_back({ radius });
}

Circle::~Circle() {
	this->m_attr.clear();
}

void Circle::printShape() const {
	cout << "Circle, [(" << this->m_attr[0][0] << ";" << this->m_attr[0][1] << "), " << this->m_attr[1][0] << "]";
}


/// ------------------------------------------------------------------------ ///
///                             printShapeInfos()                            ///
/// ------------------------------------------------------------------------ ///
void printShapeInfos(vector<Shape*> rec, vector<Shape*> tri, vector<Shape*> cir) {
	cout << "Rectangles:\n";
	for (int i = 0;i < rec.size();i++) {
		cout << "[" << i << "]: ";
		rec[i]->printShape();
		cout << "\n";
	}
	
	cout << "\nTriangles:\n";
	for (int i = 0;i < tri.size();i++) {
		cout << "[" << i << "]: ";
		tri[i]->printShape();
		cout << "\n";
	}
	
	cout << "\nCircles:\n";
	for (int i = 0;i < cir.size();i++) {
		cout << "[" << i << "]: ";
		cir[i]->printShape();
		cout << "\n";
	}
}