#include <iostream>

#include "src/vehicle.h"

using std::cin;
using std::cout;

int main() {
	Motorbike mb;
	Truck t;

	mb.addGoodsWeight(10.0f);
	mb.addFuel(50.0f);
	mb.traverse(100.0f);

	cout << "Motorbike fuel amount: " << mb.getFuelAmount() << "\n";


	t.addGoodsWeight(10.0f);
	t.addFuel(50.0f);
	t.traverse(100.0f);

	cout << "Truck fuel amount: " << t.getFuelAmount() << "\n";


	return 0;
}