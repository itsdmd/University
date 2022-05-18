#include <cmath>
#include <string>
#include <vector>

using std::stoi;
using std::string;
using std::vector;


bool all(int const &val) {
	return true;
}

bool even(int const &val) {
	return ((val % 2) == 0);
}

bool odd(int const &val) {
	return ((val % 2) != 0);
}

bool palindromic(int const &val) {
	string buffer = std::to_string(val);
	string reverse = "";
	
	for (int i = buffer.length() - 1; i >= 0; i--) {
		reverse += buffer[i];
	}
	
	return (buffer == reverse);
}

bool square(int const &val) {
	float f_val;
	
	f_val = sqrt(val);
	
	return ((f_val - (int)f_val) == 0);
}

int countCond(int const *arr, int const &size, bool (*cond)(int const &)) {
	int count = 0;

	for (int i = 0; i < size; i++) {
		if (cond(arr[i])) {
			count++;
		}
	}

	return count;
}

int countCond(vector<int> const &vt, bool (*cond)(int const &)) {
	int count = 0;

	for (int i = 0; i < vt.size(); i++) {
		if (cond(vt[i])) {
			count++;
		}
	}

	return count;
}