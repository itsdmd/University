#include "estate.h"

#include <iostream>

using std::cin;
using std::cout;

/// ------------------------------------------------------------------------ ///
///                                   Land                                   ///
/// ------------------------------------------------------------------------ ///
void Land::input() {
	cout << "Enter code: ";
	cin >> this->m_code;
	cout << "Enter price: ";
	cin >> this->m_price;
}

double Land::calcPrice() const {
	return (this->calcArea() * this->m_price);
}

/// ------------------------------------------------------------------------ ///
///                                 Rectangle                                ///
/// ------------------------------------------------------------------------ ///
void Rectangle::input() {
	Land::input();

	cout << "\nEnter height: ";
	cin >> this->m_h;
	cout << "Enter width: ";
	cin >> this->m_w;
}

double Rectangle::calcArea() const {
	return (this->m_h * this->m_w);
}

/// ------------------------------------------------------------------------ ///
///                                 Trapezoid                                ///
/// ------------------------------------------------------------------------ ///
void Trapezoid::input() {
	Land::input();

	cout << "\nEnter parallel size 1: ";
	cin >> this->m_s1;
	cout << "Enter parallel size 2: ";
	cin >> this->m_s2;
	cout << "Enter height: ";
	cin >> this->m_h;
}

double Trapezoid::calcArea() const {
	return (((this->m_s1 + this->m_s2) * this->m_h) / 2);
}

/// ------------------------------------------------------------------------ ///
///                                  Company                                 ///
/// ------------------------------------------------------------------------ ///
void Company::input() {
	int n;
	cout << "Enter number of land properties: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "\nLand property " << i + 1 << ":\n";

		int type;
		cout << "Enter type of land property (0: rectangle, 1: trapezoid): ";
		cin >> type;

		Land* land;
		switch (type) {
			case 0:
				land = new Rectangle();
				break;
			case 1:
				land = new Trapezoid();
				break;
			default:
				cout << "Invalid type of land property.\n";
				continue;
				break;
		}

		land->input();
		this->m_lands.push_back(land);
	}
}

double Company::totalArea() const {
	double area = 0;

	for (int i = 0; i < this->m_lands.size(); i++) {
		area += this->m_lands[i]->calcArea();
	}

	return area;
}

double Company::totalPrice() const {
	double price = 0;

	for (int i = 0; i < this->m_lands.size(); i++) {
		price += this->m_lands[i]->calcPrice();
	}

	return price;
}