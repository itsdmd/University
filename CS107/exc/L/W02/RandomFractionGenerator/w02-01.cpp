#include <iostream>
#include <vector>
#include "../src/frac.h"
#include "../src/rand.h"

using std::cout;
using std::vector;


/// -------------------------------- main() -------------------------------- ///
int main() {
	int size;
	vector<int> vt1, vt2;
	
	cout << "Working with randomly generated integers.\n";
	
	/// ------------------------------ Generating ------------------------------ ///
	srand(time(NULL));
	size = rng(5, 10);
	
	rndVct(vt1, size, 10, 100);
	rndVct(vt2, size, 10, 100);

	FracVct vt = FracVct(vt1, vt2);

	/// -------------------------------- Output -------------------------------- ///
	cout << "Generating " << size << " random fractions: ";
	vt.printFVct();
	
	cout << "Fractions in their lowest term: ";
	vt.printFVctReduced();
	
	cout << "Fractions in their decimal form: ";
	vt.printFVctDec();
	
	cout << "Fractions in their percentage form: ";
	vt.printFVctPct();
	
	
	return 0;
}