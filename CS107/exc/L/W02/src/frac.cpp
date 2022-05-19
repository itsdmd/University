#include <iostream>
#include <iomanip>	// std::setprecision
#include <numeric>	// std::gcd
#include "frac.h"

using std::cout;


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

void printFVct(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = vt[i];
		
		if (first) {
			cout << f.getNum() << "/" << f.getDen();
			first = false;
		}
		
		else {
			cout << ", " << f.getNum() << "/" << f.getDen();
		}
	}
	
	cout << "\n";
}

void printFVctReduced(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = vt[i];
		f = f.reduce();
		
		if (!first)
			cout << ", ";
		
		else
			first = false;
		
		if (f.getDen() == 1) {
			cout << f.getNum();
			continue;
		}
		
		cout << f.getNum() << "/" << f.getDen();
	}
	
	cout << "\n";
}

void printFVctDec(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = vt[i];
		f = f.reduce();
		
		if (!first)
			cout << ", ";
		
		else
			first = false;
		
		cout << std::setprecision(3) << ((float)f.getNum() / (float)f.getDen());
	}
	
	cout << "\n";
}

void printFVctPct(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = vt[i];
		f = f.reduce();
		
		if (!first)
			cout << ", ";
		
		else
			first = false;
		
		cout << std::setprecision(4) << ((float)f.getNum() / (float)f.getDen() * 100) << "%";
	}
	
	cout << "\n";
}