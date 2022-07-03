#include <iostream>

#include "src/cine.h"

using std::cin;
using std::cout;

int main() {
	StandardCinema c1(12, 20);
	VIPCinema c2(22, 26);

	cout << c1.seatPrice(6, 10) << "\n";
	cout << c1.seatPrice(2, 4) << "\n";
	cout << c2.seatPrice(0, 11, 17) << "\n";
	cout << c2.seatPrice(3, 11, 10) << "\n";

	cout << "\n";

	c1.bookSeat(0, 6, 10);
	cout << c1.seatAvailable(0, 6, 10) << "\n";
	c2.bookSeat(3, 11, 10);
	cout << c2.seatAvailable(5, 11, 10) << "\n";

	cout << "\n";

	cout << c1.totalPrice() << "\n";
	cout << c2.totalPrice() << "\n";

	return 0;
}