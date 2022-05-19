#include <iostream>
#include <vector>
#include "src/io.h"
#include "../src/frac.h"
#include "../src/rand.h"

using std::cout;
using std::vector;



/// -------------------------------- main() -------------------------------- ///
int main() {
	int size;
	vector<Frac> vt_f;
	Frac f_res;
	
	cout << "Working with randomly generated integers.\n";
	
	/// --------------------------------- Input -------------------------------- ///
	srand(time(NULL));
	size = rng(2, 4);
	
	cout << "Please enter " << size << " fraction";
	(size > 1) ? cout << "s:\n" : cout << ":\n";
	
	multiInput(vt_f, size);
	

	/// -------------------------------- Output -------------------------------- ///
	fracVctSum(vt_f, f_res);
	
	cout << "The sum of all entered fractions is: ";
	printFracMixed(f_res);
	
	
	return 0;
}