#include <iostream>

#include "src/hotel.h"

using std::cin;
using std::cout;


int main() {
	Hotel h1;
	
	h1.input();
	
	cout << "Total rent: " << h1.totalRent();
	
	return 0;
}