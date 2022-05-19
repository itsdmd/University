#include <iostream>
#include "io.h"
#include "../../src/frac.h"

using std::cout;
using std::getline;
using std::stoi;
using std::string;
using std::vector;


bool checkRgx(string const &target, string const &rgx_pat) {
	return std::regex_match(target, regex(rgx_pat));
}

Frac strToFrac(string const &s) {
	Frac f_res;
	int num = 0, den = 1;
	
	string num_s = "", den_s = "";
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '/') {
			num_s = s.substr(0, i);
			den_s = s.substr(i + 1);
			
			break;
		}
	}
	
	num = stoi(num_s);
	den = stoi(den_s);
	
	f_res.setNum(num);
	f_res.setDen(den);
	
	return f_res;
}

void singleInput(Frac &f_res, bool &valid) {
	Frac f;
	f.setNum(0);
	f.setDen(1);
	
	int errorCode = 0;
	string message = "";
	
	string buffer;
	getline(std::cin, buffer);
	
	if (!checkRgx(buffer, "\\d+\\/\\d+")) {
		errorCode = 1;
	}
	
	else {
		f = strToFrac(buffer);
	}
	
	tie(valid, f, errorCode, message) = Frac::parse(buffer, f);
	
	if (valid) {
		f_res.setNum(f.getNum());
		f_res.setDen(f.getDen());
		
		cout << "\n";
	}
	
	else {
		cout << message << "\n";
	}
}

void multiInput(vector<Frac> &vt_f, int const &size) {
	Frac f;
	bool valid = false;
	
	for (int i = 0; i < size; i++) {
		do {
			cout << "Fraction[" << i << "]: ";
			singleInput(f, valid);
		} while (!valid);
		
		vt_f.push_back(f);
	}
}