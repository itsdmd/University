#include <iostream>
#include <cmath>
#include "mnm.h"

using std::cout;
using std::cin;


/// ---------------------------------- I/O --------------------------------- ///
void Mnm::input() {
	cout << "Enter coefficient: ";
	cin >> coef;
	
	cout << "Enter exponent: ";
	cin >> expo;
}

void Mnm::output() {
	cout << coef << "x^" << expo;
}


/// ---------------------------------- get --------------------------------- ///
float Mnm::getCoef() {
	return coef;
}

int Mnm::getExpo() {
	return expo;
}


/// ---------------------------------- set --------------------------------- ///
void Mnm::setCoef(float const &c) {
	coef = c;
}

void Mnm::setExpo(int const &e) {
	expo = e;
}


/// --------------------------------- algos -------------------------------- ///
float Mnm::evaluate(float const &x) {
	return (coef * pow(x, expo));
}

Mnm Mnm::derive() {
	Mnm d;
	
	d.setCoef(coef * expo);
	d.setExpo(expo - 1);
	
	return d;
}

Mnm Mnm::mul(Mnm m) {
	Mnm p;
	
	p.setCoef(coef * m.getCoef());
	p.setExpo(expo + m.getExpo());
	
	return p;
}