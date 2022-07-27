#include "src/prod.h"

#include <iostream>

using std::cout;
using std::cin;

int main() {
	ProdList catalog;
	
	cout << "===== ABC Store =====\n";

	int option = 0;
	
	bool exit = false;
	while (!exit) {
		cout << "\n1. Add products\n";
		cout << "2. View products\n";
		cout << "3. Query products by manufacturer\n";
		cout << "4. Sort products by price (descending)\n";
		cout << "5. Calculate total cost obtained after all products are sold\n";
		cout << "6. Exit\n";

		do {
			cout << "\nEnter option: ";
			cin >> option;
			cin.ignore();
		} while ((option < 1) || (option > 6));
		
		switch (option) {
			case 1: {
				catalog.addProds();
				break;
			}
			
			case 2: {
				catalog.printList();
				break;
			}
			
			case 3: {
				catalog.queryByMnft();
				break;
			}
			
			case 4: {
				catalog.sortByPriceDes();
				
				cout << "\n\nSorted list (descending):";
				catalog.printList();
				break;
			}
			
			case 5: {
				cout << "Total cost obtained when all products are sold: " << catalog.calcTotalPrice() << "\n";
				break;
			}
			
			case 6: {
				cout << "\nExiting...\n";
				exit = true;
			}
		}
	}
	
	return 0;
}