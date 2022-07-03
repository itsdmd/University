#include <iostream>

#include "src/account.h"

using std::cin;
using std::cout;

int main() {
	SaveAccount acc1(1000, 6, 5, 14);
	cout << "acc1 balance: " << acc1.getBalance() << "\n";
	cout << "acc1 interest: " << acc1.calcInterest() << "\n\n";

	acc1.deposit(100);
	cout << "acc1 balance: " << acc1.getBalance() << "\n";
	cout << "acc1 interest: " << acc1.calcInterest() << "\n\n";

	for (int i = 0; i < 8; i++) {
		acc1.incrementByOneMonth();
	}
	cout << "acc1 interest: " << acc1.calcInterest() << "\n\n";

	acc1.withdraw(1200);
	cout << "acc1 balance: " << acc1.getBalance() << "\n";
	cout << "acc1 interest: " << acc1.calcInterest() << "\n";


	return 0;
}