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
	FracVct vt;
	Frac f_res;
	
	cout << "Working with randomly generated integers.\n";
	
	/// --------------------------------- Input -------------------------------- ///
	srand(time(NULL));
	size = rng(2, 4);
	
	cout << "Please enter " << size << " fraction";
	(size > 1) ? cout << "s:\n" : cout << ":\n";
	
	multiFracInp(vt, size);
	

	/// -------------------------------- Output -------------------------------- ///
	Frac f_sum = vt.fracVctSum();
	
	cout << "The sum of all entered fractions is: ";
	f_sum.printFracMixed();
	
	
	return 0;
}