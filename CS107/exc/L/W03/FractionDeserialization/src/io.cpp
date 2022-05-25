#include <fstream>
#include <iostream>

#include "io.h"

using std::cout;
using std::getline;
using std::stoi;
using std::string;
using std::vector;

/// --------------------------------- Frac --------------------------------- ///
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

void fracInp(string const &inp, Frac &f_inp, bool &valid) {
	Frac f;
	
	int errorCode = 0;
	string message = "";
	
	if (!checkRgx(inp, "\\d+\\/\\d+")) {
		valid = false;
		return;
	}
	
	else {
		f = strToFrac(inp);
	}
	
	tie(valid, f, errorCode, message) = Frac::parse(inp, f);
	
	if (valid) {
		f_inp.setNum(f.getNum());
		f_inp.setDen(f.getDen());
	}
	
	else {
		return;
	}
}


/// --------------------------------- File --------------------------------- ///
int loadData(string const &dir, FracVct &fvt) {
	std::ifstream inp(dir);
	
	if (!inp.is_open()) {
		std::cout << "Error opening file: " << dir << std::endl;
		return 1;
	}
	
	int n;
	inp >> n;
	if (n == 0) {
		return 0;
	}
	
	
	while (inp) {
		string line;
		
        if (getline(inp, line)) {
			bool valid = false;
			Frac f;
			
			fracInp(line, f, valid);
			
			if (valid) {
				fvt.addElement(f);
			}
        }
    }
	
	inp.close();
	return 0;
}