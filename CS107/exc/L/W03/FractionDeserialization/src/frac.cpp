#include <iostream>
#include <iomanip>	// std::setprecision
#include <numeric>	// std::gcd

#include "frac.h"

using std::cout;


/// ------------------------------------------------------------------------ ///
///                                   Frac                                   ///
/// ------------------------------------------------------------------------ ///

/// ------------------------------- Cstr/Dstr ------------------------------ ///
Frac::Frac() {
	this->num = 0;
	this->den = 1;
}

Frac::Frac(int n, int d) {
	this->num = n;
	this->den = d;
}

/// -------------------------------- get/set ------------------------------- ///
int Frac::getNum() {
	return this->num;
}

int Frac::getDen() {
	return this->den;
}

void Frac::setNum(int const &n) {
	this->num = n;
}

void Frac::setDen(int const &d) {
	this->den = d;
}

/// --------------------------------- Algos -------------------------------- ///
Frac Frac::reduce() {
	int gcd = std::gcd(this->num, this->den);
	
	this->num /= gcd;
	this->den /= gcd;
	
	return *this;
}

/// --------------------------------- print -------------------------------- ///
void Frac::printFrac() {
	if (this->getDen() == 1) {
		cout << this->getNum();
	}
	
	else {
		cout << this->getNum() << "/" << this->getDen();
	}
}

void Frac::printFracMixed() {
	int whole = this->getNum() / this->getDen();
	int new_num = this->getNum() % this->getDen();
	
	if (whole == 0) {
		cout << new_num << "/" << this->getDen();
	}
	
	else {
		cout << whole << " " << new_num << "/" << this->getDen();
	}
}

/// ------------------------------------------------------------------------ ///
///                                  FracVct                                 ///
/// ------------------------------------------------------------------------ ///

/// ------------------------------- Cstr/Dstr ------------------------------ ///
FracVct::FracVct() {
	this->vt.reserve(1);
}

FracVct::FracVct(FracVct const &other) {
	this->vt = other.vt;
}

FracVct::FracVct(vector<int> const &fv1, vector<int> const &fv2) {
	Frac f;
	
	for (int i = 0; i < fv1.size(); i++) {
		f.setNum(fv1[i]);
		f.setDen(fv2[i]);
		
		this->vt.push_back(f);
	}
}

FracVct::~FracVct() {
	this->vt.clear();
}

/// -------------------------------- get/set ------------------------------- ///
vector<Frac> FracVct::getVct() {
	return this->vt;
}

Frac FracVct::getElement(int const &i) {
	return this->vt[i];
}

void FracVct::setElement(int const &i, Frac const &f) {
	this->vt[i] = f;
}

void FracVct::addElement(Frac const &f) {
	this->vt.push_back(f);
}

/// --------------------------------- print -------------------------------- ///
void FracVct::printFVct() {
	bool first = true;
	
	for (int i = 0; i < this->vt.size(); i++) {
		if (first) {
			first = false;
		}
		
		else {
			cout << ", ";
		}
		
		this->vt[i].printFrac();
	}
	
	cout << "\n";
}

void FracVct::printFVctReduced() {
	bool first = true;
	
	for (int i = 0; i < this->vt.size(); i++) {
		Frac f = this->vt[i].reduce();
		
		if (first) {
			first = false;
		}
		
		else {
			cout << ", ";
		}
		
		f.printFracMixed();
	}
	
	cout << "\n";
}

void FracVct::printFVctDec() {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = this->vt[i].reduce();
		
		if (!first)
			cout << ", ";
		
		else
			first = false;
		
		cout << std::setprecision(3) << ((float)f.getNum() / (float)f.getDen());
	}
	
	cout << "\n";
}

void FracVct::printFVctPct() {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = this->vt[i].reduce();
		
		if (!first)
			cout << ", ";
		
		else
			first = false;
		
		cout << std::setprecision(4) << ((float)f.getNum() / (float)f.getDen() * 100) << "%";
	}
	
	cout << "\n";
}

/// ------------------------------ Calculation ----------------------------- ///
Frac FracVct::fracVctSum() {
	Frac f_res;
	
	Frac temp_f = this->vt[0];
	f_res.setNum(temp_f.getNum());
	f_res.setDen(temp_f.getDen());
	
	for (int i = 1; i < this->vt.size(); i++) {
		temp_f = this->vt[i];
		
		int temp_n = 0;
		int temp_d = 1;
		
		temp_n = (f_res.getNum() * temp_f.getDen()) + (temp_f.getNum() * f_res.getDen());
		temp_d = (f_res.getDen() * temp_f.getDen());
		
		f_res.setNum(temp_n);
		f_res.setDen(temp_d);
		
		f_res.reduce();
	}
	
	return f_res;
}