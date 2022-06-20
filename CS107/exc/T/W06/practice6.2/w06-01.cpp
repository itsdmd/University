#include <iostream>

#include "src/account.h"

using std::cin;
using std::cout;

int main() {
	SaveAccount acc1(1000, 6, 5, 0);

	cout << "acc1 balance: " << acc1.getBalance() << "\n";

	acc1.deposit(100);

	cout << "acc1 balance: " << acc1.getBalance() << "\n";

	acc1.withdraw(2200);

	cout << "acc1 balance: " << acc1.getBalance() << "\n";


	return 0;
}