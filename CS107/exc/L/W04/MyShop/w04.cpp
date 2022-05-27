#include <iostream>
#include <string>
#include <vector>

#include "src/ctg.h"
#include "src/io.h"
#include "src/prod.h"

using std::cout;
using std::string;


int main () {
	string const prod_dir_full = "/home/dmd/Documents/University/CS107/exc/L/W04/MyShop/products.txt";
	string const ctg_dir_full = "/home/dmd/Documents/University/CS107/exc/L/W04/MyShop/categories.txt";
	string const prod_dir = "products.txt";
	string const ctg_dir = "categories.txt";
	
	ProdVct pvt;
	CtgVct cvt;
	
	cout << "===== My Shop =====\n\n";
	
	readProd(pvt, prod_dir_full);
	readCtg(cvt, ctg_dir_full);
	
	int choice = main_menu();
	do {
		switch (choice) {
			case 1:
				print_AllCtg(pvt, cvt);
				break;
			case 2:
				print_ProdByName(pvt, cvt);
				break;
			case 3:
				print_ProdByPriceRange(pvt, cvt);
				break;
			default:
				break;
		}
		
		choice = main_menu();
	} while (choice != 0);
	
	cout << "\nQuitting...";
	return 0;
}