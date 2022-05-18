#pragma once

#include <iostream>
#include <numeric> // std::gcd
#include <vector>
#include "frac.h"

using std::cout;
using std::vector;


int Frac::getNum() {
	return num;
}

int Frac::getDen() {
	return den;
}

void Frac::setNum(int const &n) {
	num = n;
}

void Frac::setDen(int const &d) {
	den = d;
}

Frac Frac::reduce() {
	int gcd = std::gcd(num, den);
	
	num /= gcd;
	den /= gcd;
	
	return *this;
}

void fracVctGen(vector<int> const &vt1, vector<int> const &vt2, vector<Frac> &vt_f) {
	Frac f;
	
	for (int i = 0; i < vt1.size(); i++) {
		f.setNum(vt1[i]);
		f.setDen(vt2[i]);
		
		vt_f.push_back(f);
	}
}