#include <iostream>
#include <vector>
#include "../src/io.cpp"
#include "../src/randomize.cpp"

using std::cout;
using std::vector;


int main() {
	int size;
	vector<int> vt;
	
	cout << "Working with randomly generated integers.\n";
	
	srand(time(NULL));
	size = random(5, 10);
	
	cout << "Generating " << size << " random integers: ";
	rndVct(vt, size, 10, 100);
	printVct(vt, all);
	cout << "\n";
	
	/// --------------------------------- Output -------------------------------- ///
	printCond("even", vt, even);
	printCond("odd", vt, odd);
	printCond("palindromic", vt, palindromic);
	printCond("square", vt, square);
	
	return 0;
}