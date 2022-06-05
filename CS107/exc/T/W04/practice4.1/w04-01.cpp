#include <iostream>

#include "src/frac.h"

using std::cout;
using std::cin;


int main() {
	Frac f1(1, 2);
	Frac f2(2, 3);
	
	Frac f3 = ((f1++) + f2);
	Frac f4 = (f1 * (--f2));
	
	cout << f3 << "\n";
	cout << f4 << "\n";
	
	cout << (f3 < f4) << "\n";
	
	cout << (f3 += f4).reduce() << "\n";
	
	f1 = f2 = f3 = f4;
	
	cout << f1 << " " << f2 << " " << f3 << " " << f4 << "\n";
	
	cout << int(f1) << " || " << float(f2) << "\n";
	
	
	return 0;
}