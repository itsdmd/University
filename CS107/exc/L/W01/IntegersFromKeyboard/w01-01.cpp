#include <iostream>
#include "../src/io.cpp"

using std::cin;
using std::cout;
using std::getline;
using std::stoi;
using std::string;


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
	printArr(arr, size, all);
	
	/// --------------------------------- Output -------------------------------- ///
	printCond("even", arr, size, even);
	printCond("odd", arr, size, odd);
	printCond("palindromic", arr, size, palindromic);
	printCond("square", arr, size, square);
	
	return 0;
}