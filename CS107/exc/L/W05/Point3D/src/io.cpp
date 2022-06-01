#include <fstream>
#include <iostream>
#include <regex>

#include "io.h"

using std::cout;
using std::cin;


bool checkRgx(string const &target, string const &rgx_pat) {
	return std::regex_match(target, std::regex(rgx_pat));
}

vector<string> input3D(int const &n) {
	vector<string> inp;
	string line;
	
	for (int i = 0; i < n; i++) {
		cout << "[" << i << "] = ";
		
		getline(cin, line);
		inp.push_back(line);
	}
	
	
	return inp;
}

vector<Point3D> extractor3D(vector<string> const &inp) {
	vector<Point3D> vtp3;
	
	for (int i = 0; i < inp.size(); i++) {
		double x = 0;
		double y = 0;
		double z = 0;
		
		if (!checkRgx(inp[i], "^\\d+,\\ \\d+,\\ \\d+$")) {
			continue;
		}
		
		string::size_type pos1 = 0;
		string::size_type pos2 = inp[i].find(',', pos1);
		try {
			x = stod(inp[i].substr(pos1, (pos2 - pos1)));
		} catch (...) {
			continue;
		}
		
		pos1 = (pos2 + 2);
		pos2 = inp[i].find(',', pos1);
		try {
			y = stod(inp[i].substr(pos1, (pos2 - pos1)));
		} catch (...) {
			continue;
		}
		
		pos1 = (pos2 + 2);
		pos2 = inp[i].find('\n', pos1);
		try {
			z = stod(inp[i].substr(pos1, (pos2 - pos1)));
		} catch (...) {
			continue;
		}
		
		vtp3.push_back(Point3D(x, y, z));
	}
	
	
	return vtp3;
}


void printVector3D(vector<Point3D> const &vtp3) {
	for (int i = 0; i < vtp3.size(); i++) {
		cout << "[" << i << "] = ";
		vtp3[i].print();
		cout << "\n";
	}
}

void writeFile(string const &file_name, vector<Point3D> const &vtp3) {
	std::ofstream fout(file_name);
	
	for (int i = 0; i < vtp3.size(); i++) {
		fout << "(" << vtp3[i].getX() << ", " << vtp3[i].getY() << ", " << vtp3[i].getZ() << ")" << "\n";
	}
	
	fout.close();
}