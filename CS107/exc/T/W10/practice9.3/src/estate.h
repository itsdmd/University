#ifndef ESTATE_H
#define ESTATE_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Land {
	protected:
		string m_code;
		double m_price;				  // price per square meter

	public:
		virtual void input();
		virtual double calcArea() const = 0;
		double calcPrice() const;
};

class Rectangle: public Land {
	private:
		double m_h = 0;
		double m_w = 0;

	public:
		void input() override;
		double calcArea() const override;
};

class Trapezoid: public Land {
	private:
		double m_s1 = 0;
		double m_s2 = 0;
		double m_h = 0;

	public:
		void input() override;
		double calcArea() const override;
};

class Company {
	private:
		vector<Land *> m_lands;

	public:
		void input();
		double totalArea() const;
		double totalPrice() const;
};

#endif