#include <iostream>
#include <string>
#include <vector>

#include "src/ctgr.h"
#include "src/io.h"
#include "src/prod.h"

using std::cout;
using std::string;


int main () {
	string const prod_dir_full = "/home/dmd/Documents/University/CS107/exc/L/W04/MyShop/products.txt";
	string const ctgr_dir_full = "/home/dmd/Documents/University/CS107/exc/L/W04/MyShop/categories.txt";
	string const prod_dir = "products.txt";
	string const ctgr_dir = "categories.txt";
	
	ProdVct pvt;
	CtgrVct cvt;
	
	cout << "===== My Shop =====\n\n";
	
	readProd(pvt, prod_dir_full);
	readCtgr(cvt, ctgr_dir_full);
	
	int choice = 0;
	do {
		choice = main_menu();
		
		switch (choice) {
			case 1:
				print_AllCtgr(pvt, cvt);
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
	} while (choice != 0);
	
	cout << "\nQuitting...";
	return 0;
}