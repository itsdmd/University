#pragma once

#include <iomanip>	// std::setprecision
#include <iostream>
#include <vector>
#include "frac.cpp"

using std::cout;
using std::vector;


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