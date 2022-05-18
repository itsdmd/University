#include <iostream>
#include <vector>
#include "../src/frac.cpp"
#include "../src/rand.cpp"
#include "../src/io.cpp"

using std::cout;
using std::vector;


/// -------------------------------- main() -------------------------------- ///
int main() {
	int size;
	vector<int> vt1, vt2;
	vector<Frac> vt_f;
	
	cout << "Working with randomly generated integers.\n";
	
	/// ------------------------------ Generating ------------------------------ ///
	size = rng(5, 10);
	
	rndVct(vt1, size, 10, 100);
	rndVct(vt2, size, 10, 100);

	fracVctGen(vt1, vt2, vt_f);

	/// -------------------------------- Output -------------------------------- ///
	cout << "Generating " << size << " random fractions: ";
	printFVct(vt_f);
	
	cout << "Fractions in their lowest term: ";
	printFVctReduced(vt_f);
	
	cout << "Fractions in their decimal form: ";
	printFVctDec(vt_f);
	
	cout << "Fractions in their percentage form: ";
	printFVctPct(vt_f);
	
	
	return 0;
}