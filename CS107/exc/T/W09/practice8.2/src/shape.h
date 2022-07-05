#ifndef SHAPE_H
#define SHAPE_H

#include <vector>

using std::vector;

class Shape {
	protected:
		vector<vector<float>> m_attr;				// Store shape's attributes

	public:
		Shape() { this->m_attr.resize(0); };

		virtual ~Shape() { this->m_attr.clear(); };

		virtual void printShape() const = 0;			   // Print shape's attributes
};

class Rectangle: public Shape {
	public:
		Rectangle();
		Rectangle(const float x_top, const float y_top, const float x_low, const float y_low);
		~Rectangle();

		void printShape() const override;
};

class Triangle: public Shape {
	public:
		Triangle();
		Triangle(const float x_1, const float y_1, const float x_2, const float y_2, const float x_3, const float y_3);
		~Triangle();

		void printShape() const override;
};

class Circle: public Shape {
	public:
		Circle();
		Circle(const float x_center, const float y_center, const float radius);
		~Circle();

		void printShape() const override;
};

void printShapeInfos(vector<Shape*> rec, vector<Shape*> tri, vector<Shape*> cir);			   // Print formatted attributes of shapes inside a vector

#endif