#include <fstream>
#include <iostream>
#include <string>

#include "src/frac.h"
#include "src/io.h"

using std::cin;
using std::cout;
using std::string;


/// -------------------------------- main() -------------------------------- ///
int main() {
	const string dir_full = "/home/dmd/Documents/University/CS107/exc/L/W03/FractionDeserialization/data.txt";
	const string dir = "data.txt";
	
	FracVct fvt;
	
	cout << "Fraction deserialization\n\n";
	cout << "Reading fractions from " << dir << " file...\n\n";
	
	loadData(dir_full, fvt);
	
	int size = fvt.getVct().size();
	cout << "Found " << size << " fraction";
	(size > 1) ? cout << "s: " : cout << ": ";
	
	fvt.printFVctReduced();
	
	cout << "\nThe sum of all fractions is: ";
	Frac sum = fvt.fracVctSum();
	sum.printFracMixed();
	
	
	return 0;
}