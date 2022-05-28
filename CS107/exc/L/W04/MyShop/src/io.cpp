#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "io.h"

using std::cout;
using std::cin;
using std::getline;
using std::string;
using std::vector;


/// ------------------------------------------------------------------------ ///
///                                Extractors                                ///
/// ------------------------------------------------------------------------ ///
/* #region   */
// Returns a Prod object from a string
Prod prod_extract(string const &line) {
	int id;
	string name;
	long price;
	int ctgr;
	
	// ID
	string::size_type pos1 = line.find('=', 0) + 1;
	string::size_type pos2 = line.find(',', pos1);
	id = stoi(line.substr(pos1, (pos2 - pos1)));
	
	// Name
	pos1 = line.find('=', (pos2 + 1)) + 1;
	pos2 = line.find(',', pos1);
	name = line.substr(pos1, (pos2 - pos1));
	
	// Price
	pos1 = line.find('=', (pos2 + 1)) + 1;
	pos2 = line.find(',', pos1);
	string price_raw = line.substr(pos1, (pos2 - pos1));
	// -- Remove the dots
	size_t dot_pos = std::string::npos;
    while ((dot_pos = price_raw.find(".")) != string::npos) {		// Loop until can't find any dot
        price_raw.erase(dot_pos, 1);
    }
	price = stod(price_raw);
	
	// Category
	pos1 = line.find('=', (pos2 + 1)) + 1;
	pos2 = line.find(',', pos1);
	ctgr = stoi(line.substr(pos1, (pos2 - pos1)));
	
	
	return Prod(id, name, price, ctgr);
}

// Returns a Ctgr object from a string
Ctgr ctgr_extract(string const &line) {
	int id;
	string name;
	
	// ID
	string::size_type pos1 = line.find('=', 0) + 1;
	string::size_type pos2 = line.find(',', pos1);
	id = stoi(line.substr(pos1, (pos2 - pos1)));
	
	// Name
	pos1 = line.find('=', (pos2 + 1)) + 1;
	pos2 = line.find(',', pos1);
	name = line.substr(pos1, (pos2 - pos1));
	
	return Ctgr(id, name);
}
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                  Readers                                 ///
/// ------------------------------------------------------------------------ ///
/* #region   */
// Read products from a file
void readProd(ProdVct &pvt, string const &dir) {
	std::ifstream inp(dir);
	
	if (!inp.is_open()) {
		std::cout << "Error: Cannot open " << dir << " for reading.\n";
		exit(1);
	}
	
	while (inp) {
		string line;
		
        if (getline(inp, line)) {
			pvt.add_prod(prod_extract(line));
        }
    }
	
	inp.close();
}

// Read categories from a file
void readCtgr(CtgrVct &cvt, string const &dir) {
	std::ifstream inp(dir);
	
	if (!inp.is_open()) {
		std::cout << "Error: Cannot open " << dir << " for reading.\n";
		exit(1);
	}
	
	while (inp) {
		string line;
		
        if (getline(inp, line)) {
			cvt.add_ctgr(ctgr_extract(line));
        }
    }
	
	inp.close();
}
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                 Interface                                ///
/// ------------------------------------------------------------------------ ///
/* #region   */
// Welcome interface
int main_menu() {
	int option;
	
	cout << "\nWhat do you want to do?\n"
			<< "1. Display all categories\n"
			<< "2. Find products by name\n"
			<< "3. Find products by price range\n"
			<< "\n"
			<< "0. Quit"
			<< "\n\n";
	
	cout << "Please enter your choice: ";
	cin >> option;
	while ((option < 0) || (option > 3)) {
		cout << "Invalid option. Please enter a number from 0 to 3: ";
		cin >> option;
	}
	
	return option;
}

/// --------------------------------- sort --------------------------------- ///
/* #region   */
// Sort ProdVct by ID
vector<Prod> sort_vct(ProdVct pvt) {
	vector<Prod> sorted_vtp = pvt.get_vct();
	
	for (int i = 0; i < sorted_vtp.size(); i++) {
		for (int j = 0; j < (sorted_vtp.size() - 1); j++) {
			if (sorted_vtp[j].get_id() > sorted_vtp[j + 1].get_id()) {
				Prod temp = sorted_vtp[j];
				sorted_vtp[j] = sorted_vtp[j + 1];
				sorted_vtp[j + 1] = temp;
			}
		}
	}
	
	return sorted_vtp;
}

// Sort CtgrVct by ID
vector<Ctgr> sort_vct(CtgrVct cvt) {
	vector<Ctgr> sorted_vct = cvt.get_vct();
	
	for (int i = 0; i < sorted_vct.size(); i++) {
		for (int j = 0; j < (sorted_vct.size() - 1); j++) {
			if (sorted_vct[j].get_id() > sorted_vct[j + 1].get_id()) {
				Ctgr temp = sorted_vct[j];
				sorted_vct[j] = sorted_vct[j + 1];
				sorted_vct[j + 1] = temp;
			}
		}
	}
	
	return sorted_vct;
}
/* #endregion */

/// --------------------------------- print -------------------------------- ///
/* #region   */
// Print formatted data of a Prod object
void printProd(Prod p, CtgrVct cvt) {
	cout << "Category: " << cvt.get_ctgr(p.get_ctgr()).get_name()
			<< ", ID: " << p.get_id()
			<< ", Name: " << p.get_name()
			<< ", Price: " << p.get_price() << " d";
}

// Print formatted data of a Ctgr object
void printCtgr(Ctgr c) {
	cout << "ID: " << c.get_id() << ", Name: " << c.get_name();
}

// Print formatted data of Prod objects from a search result
void printSearchRes(vector<Prod> const &vtp, CtgrVct const &cvt) {
	if (vtp.size() == 0) {
		cout << "\nNo product with given criteria was found.\n";
		return;
	}
	
	cout << "\nFound " << vtp.size() << " product";
	(vtp.size() > 1) ? (cout << "s.\n") : (cout << ".\n");
	for (int i = 0; i < vtp.size(); i++) {
		cout << i + 1 << ". ";
		printProd(vtp[i], cvt);
		cout << "\n";
	}
}

// Print formatted data of all categories
void print_AllCtgr(ProdVct pvt, CtgrVct cvt) {
	cout << "\n=== List of all categories ===\n";
	cout << "Found " << cvt.get_vct().size() << " categories.\n";
	
	int i = 1;
	for (Ctgr &c : cvt.get_vct()) {
		cout << i << ". ";
		printCtgr(c);
		cout << "\n";
		
		i++;
	}
	
	int option;
	cout << "\nSelect a category to display its products: ";
	cin >> option;
	while ((option < 1) || (option > cvt.get_vct().size())) {
		cout << "Invalid category ID. Please enter a number from 1 to " << cvt.get_vct().size() << ": ";
		cin >> option;
	}
	
	int ctgr_id = cvt.get_vct()[option - 1].get_id();
	
	cout << "\n\n=== List of products in \"" << cvt.get_ctgr(ctgr_id).get_name() << "\" category ===\n";
	i = 1;
	for (Prod &p : pvt.get_vct()) {
		if (p.get_ctgr() == ctgr_id) {
			cout << i << ". ";
			printProd(p, cvt);
			cout << "\n";
			
			i++;
		}
	}
}

// Print formatted data of all products that their name contains a given keyword
void print_ProdByName(ProdVct pvt, CtgrVct const &cvt) {
	string keyword;
	
	cout << "Enter the ID of the product you want to find: ";
	do {
      getline(cin, keyword);
    } while(keyword == "");
	cout << "\nSearching for \"" << keyword << "\"...\n";
	
	printSearchRes(pvt.get_vct(keyword), cvt);
}

// Print formatted data of all products that their price is within a given value range
void print_ProdByPriceRange(ProdVct pvt, CtgrVct const &cvt) {
	long min_price, max_price;
	
	cout << "Enter the minimum price: ";
	cin >> min_price;
	cout << "Enter the maximum price: ";
	cin >> max_price;
	while (min_price > max_price) {
		cout << "Maximum price must be less than or equal to minimum price.";
		cout << "\nEnter the maximum price: ";
		cin >> max_price;
	}
	
	cout << "\n=== List of products within the price range of [" << min_price << ", " << max_price << "] ===\n";
	
	printSearchRes(pvt.get_vct(min_price, max_price), cvt);
}
/* #endregion */
/* #endregion */