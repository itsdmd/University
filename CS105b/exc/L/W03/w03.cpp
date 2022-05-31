#include <algorithm>
#include <fstream>
#include <iomanip>		// std::setw
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::vector;


/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///
void readFile(string const &dir, vector<string> &bs) {
	std::ifstream inp(dir);
	
	if (!inp.is_open()) {
		std::cout << "Error: Cannot open " << dir << " for reading.\n";
		
		inp.close();
		exit(1);
	}
	
	string line = "";
	getline(inp, line);
	
	inp.close();
	
	string qt = "";
	for (char const &c: line) {
		if (c == '\n') {
			if (qt != "") {
				bs.push_back(qt);
			}
			
			break;
		} else if (c == ' ') {
			bs.push_back(qt);
			qt = "";
		} else {
			qt += c;
		}
	}
}


unsigned long convertHexToDec(string const &hex) {
	unsigned long res = 0;
	
	res = std::stoul (hex, nullptr, 16);
	
	
	return res;
}


string readBytes(vector<string> const &bs, int index, int length) {
	if (length > (index + 1)) {
		std::cout << "Error: Invalid length.\n";
		
		exit(1);
	} else if (length == 0) {
		return "";
	}
	
	string res = "";
	
	for (int i = 0; i < length; i++) {
		res += bs[index - i];
	}
	
	
	for (int i = 0; i < length; i++) {
		res += res[0];
		res += res[1];
		
		res.erase(res.begin());
		res.erase(res.begin());
	}
	
	
	return res;
}


//TODO
void convertHexToString(string const &hex) {
	std::stringstream ss;
	
	string hex1 = hex.substr(0, 3);
	string hex2 = hex.substr(4, 7);
	
	int val1 = 0;
	int val2 = 0;
	
	ss << hex1;
	ss >> std::hex >> val1;
	ss << hex2;
	ss >> std::hex >> val2;
	
	while (val1 != 0) {
		cout << (char)(val1 % 100);
		
		val1 /= 100;
	}
	
	while (val2 != 0) {
		cout << (char)(val2 % 100);
		
		val2 /= 100;
	}
}


void print(vector<string> const &bs) {
	string s = readBytes(bs, 0x0B, 2);
	cout << "Bytes of a sector: " << s << " " << convertHexToDec(s) << "\n";
	s = readBytes(bs, 0x0D, 1);
	cout << "Sectors of a cluster: " << s << " " << convertHexToDec(s) << "\n";
	s = readBytes(bs, 0x0E, 2);
	cout << "Sectors before FAT: " << s << " " << convertHexToDec(s) << "\n";
	s = readBytes(bs, 0x10, 1);
	cout << "Number of FAT: " << s << " " << convertHexToDec(s) << "\n";
	s = readBytes(bs, 0x11, 2);
	cout << "RDET's entries: " << s << " " << convertHexToDec(s) << "\n";
	// RDET's entries * 32 * bytes of a sector
	cout << "RDET's sectors: " << (convertHexToDec(s) * 32 * convertHexToDec(readBytes(bs, 0x0B, 2))) << "\n";
	s = readBytes(bs, 0x13, 2);
	cout << "Sectors of a volume: " << s << " " << convertHexToDec(s) << "\n";
	s = readBytes(bs, 0x16, 2);
	cout << "Sectors of a FAT: " << s << " " << convertHexToDec(s) << "\n";
	if (convertHexToDec(readBytes(bs, 0x13, 1)) == 0) {
		s = readBytes(bs, 0x20, 4);
		cout << "Sectors of a volume: " << s << " " << convertHexToDec(s) << "\n";
	}
	s = readBytes(bs, 0x36, 8);
	cout << "FAT type: ";
	convertHexToString(s);
}



/// -------------------------------- main() -------------------------------- ///
int main() {
	string const dir_full = "/home/dmd/Documents/University/CS105b/exc/L/W03/bootsector.txt";
	string const dir = "bootsector.txt";
	vector<string> bs;
	
	readFile(dir_full, bs);
	
	for (auto i : bs) {
		cout << i << std::setw(4);
	}
	cout << "\n\n";
	
	print(bs);
	
	
	return 0;
}