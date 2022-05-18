#include <iostream>
#include <string>
#include "algos.cpp"

using std::cin;
using std::cout;
using std::getline;
using std::stoi;
using std::string;


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