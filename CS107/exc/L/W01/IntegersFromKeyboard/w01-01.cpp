#include <cmath>
#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::getline;
using std::stoi;
using std::string;


/// ------------------------------------------------------------------------ ///
///                                 Functions                                ///
/// ------------------------------------------------------------------------ ///

/// --------------------------------- Algos -------------------------------- ///
/* #region   */
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
/* #endregion */

/// ---------------------------------- I/O --------------------------------- ///
/* #region   */
void inp_int(int &target, bool &success) {
	string buffer;

	getline(cin, buffer);
	
	if (buffer == "") {
		cout << "Error: Empty input.";
		
		success = 0;
		return;
	}
	
	try {
		target = stoi(buffer);
	}
	
	catch (...) {
		cout << "Error: Invalid input format.";
		
		success = 0;
		return;
	}
	
	success = 1;
	return;
}

void singleInput(string const &msg, int &val, int const &min, int const &max) {
	bool valid = 0;
	
	cout << msg;
	inp_int(val, valid);
	
	while ((val <= min) || (val >= max)) {
		valid ?
			cout << "Error: The integer must be in the range of [" << min << ", " << max << "]\n"
			:
			cout << "\n";
		
		cout << msg;
		inp_int(val, valid);
	}
}

void multiInput(int *arr, int const &count, int const &min, int const &max) {
	int val = 0;

	for (int i = 0; i < count; i++) {
		string msg = "The [" + std::to_string(i) + "] integer: ";
		singleInput(msg, val, min, max);
		
		arr[i] = val;
	}
}

void printArray(int const *arr, int const &size, bool (*cond)(int const &)) {
	bool first = true;
	
	for (int i = 0; i < size; i++) {
		if (cond(arr[i])) {
			if (first) {
				cout << arr[i];
				first = false;
			}
			
			else {
				cout << ", " << arr[i];
			}
		}
	}
	cout << "\n";
}

void beautified(string const &msg, int const *arr, int const &size, bool (*cond)(int const &)) {
	cout << "Found " << countCond(arr, size, cond) << " " << msg << " number";
	(size > 1) ? (cout << "s: ") : (cout << ": ");
	printArray(arr, size, cond);
}
/* #endregion */


/// -------------------------------- main() -------------------------------- ///
int main() {
	int size;
	int arr[10];
	
	cout << "Working with integer arrays from the keyboard.\n";
	
	singleInput("Please enter an integer in the range of [5, 10]: ", size, 5, 10);
	
	/// --------------------------------- Input -------------------------------- ///
	cout << "\nPlease enter " << size << " integer";
	(size > 1) ? (cout << "s") : (cout << "");
	cout << ", each in the range of [1, 100]:\n";
	multiInput(arr, 6, 1, 100);
	
	cout << "You have entered " << size << " integer";
	(size > 1) ? (cout << "s: ") : (cout << ": ");
	printArray(arr, size, all);
	
	/// --------------------------------- Output -------------------------------- ///
	beautified("even", arr, size, even);
	beautified("odd", arr, size, odd);
	beautified("palindromic", arr, size, palindromic);
	beautified("square", arr, size, square);
	
	return 0;
}