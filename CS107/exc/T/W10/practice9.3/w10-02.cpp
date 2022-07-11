#include <iostream>

#include "src/estate.h"

using std::cin;
using std::cout;

int main() {
	Company c1;

	c1.input();

	cout << "Total area: " << c1.totalArea() << "\n";
	cout << "Total price: " << c1.totalPrice() << "\n";

	return 0;
}