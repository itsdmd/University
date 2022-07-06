#ifndef SHAPE_H
#define SHAPE_H

#include <string>

using std::string;

class Shape {
	public:
		Shape() {};
		virtual ~Shape() {};

		virtual double area() const = 0;
		virtual double perimeter() const = 0;

		virtual string print(bool withCalculation) const = 0;
};

class Rectangle: public Shape {
	private:
		float m_width;
		float m_height;

	public:
		Rectangle(float width, float height);

		double area() const override;
		double perimeter() const override;

		string print(bool withCalculation) const override;
};

class Triangle: public Shape {
	private:
		float m_a;
		float m_b;
		float m_c;

	public:
		Triangle(float a, float b, float c);

		double area() const override;
		double perimeter() const override;

		string print(bool withCalculation) const override;
};

class Circle: public Shape {
	private:
		float m_radius;

	public:
		Circle(float radius);

		double area() const override;
		double perimeter() const override;

		string print(bool withCalculation) const override;
};

#endif