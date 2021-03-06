#include <iostream>
#include <numeric> // std::gcd
#include "frac.h"
#include "swap.h"

using std::cout;
using std::cin;


/// ---------------------------------- I/O --------------------------------- ///
void Frac::input() {
	cout << "Enter numerator: ";
	cin >> num;
	
	do {
		cout << "Enter denominator: ";
		cin >> den;
	} while (den == 0);
}

void Frac::output() {
	if (num >= 0 && den < 0) {
		num *= -1;
	}
	
	if (num == 0) {
		cout << "0";
	}
	
	else if (den == 1) {
		cout << num;
	}
	
	else {
		cout << num << "/" << den;
	}
}


/// ---------------------------------- get --------------------------------- ///
int Frac::getNum() {
	return num;
}

int Frac::getDen() {
	return den;
}

/// ---------------------------------- set --------------------------------- ///
void Frac::setNum(int const &n) {
	num = n;
}

void Frac::setDen(int const &d) {
	den = d;
}


/// --------------------------------- algos -------------------------------- ///
Frac Frac::reduce() {
	int gcd = std::gcd(num, den);
	
	num /= gcd;
	den /= gcd;
	
	return *this;
}

Frac Frac::inverse() {
	if (num == 0) {
		cout << "Cannot invert 0\n";
	}
	
	else {
		swap(num, den);
	}
	
	
	return *this;
}

Frac Frac::add(Frac const &f) {
	Frac res;
	
	res.num = (num * f.den) + (den * f.num);
	res.den = (den * f.den);
	
	return res.reduce();
}

int Frac::compare(Frac const &f) {
	double f1_d, f2_d;
	
	f1_d = (double)num / (double)den;
	f2_d = (double)f.num / (double)f.den;
	
	if (f1_d > f2_d) {
		return 1;
	}
	
	else if (f1_d < f2_d) {
		return -1;
	}
	
	else {
		return 0;
	}
}