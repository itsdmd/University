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

void fracVctSum(vector<Frac> const &vt_inp, Frac &f_res) {
	int temp_n = 0;
	int temp_d = 1;
	
	Frac temp_f = vt_inp[0];
	f_res.setNum(temp_f.getNum());
	f_res.setDen(temp_f.getDen());
	
	for (int i = 1; i < vt_inp.size(); i++) {
		temp_f = vt_inp[i];
		
		temp_n = (f_res.getNum() * temp_f.getDen()) + (temp_f.getNum() * f_res.getDen());
		temp_d = (f_res.getDen() * temp_f.getDen());
		
		f_res.setNum(temp_n);
		f_res.setDen(temp_d);
		
		f_res.reduce();
	}
}

void printFrac(Frac f) {
	if (f.getDen() == 1) {
		cout << f.getNum();
	}
	
	else {
		cout << f.getNum() << "/" << f.getDen();
	}
}

void printFracMixed(Frac f) {
	int whole = f.getNum() / f.getDen();
	int new_num = f.getNum() % f.getDen();
	
	if (whole == 0) {
		cout << new_num << "/" << f.getDen();
	}
	
	else {
		cout << whole << " " << new_num << "/" << f.getDen();
	}
}

void printFVct(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		if (first) {
			first = false;
		}
		
		else {
			cout << ", ";
		}
		
		printFrac(vt[i]);
	}
	
	cout << "\n";
}

void printFVctReduced(vector<Frac> const &vt) {
	bool first = true;
	
	for (int i = 0; i < vt.size(); i++) {
		Frac f = vt[i];
		f = f.reduce();
		
		if (first) {
			first = false;
		}
		
		else {
			cout << ", ";
		}
		
		printFracMixed(f);
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