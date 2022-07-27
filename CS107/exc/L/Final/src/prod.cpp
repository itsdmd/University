#include "prod.h"

#include <iostream>

using std::cin;
using std::cout;
using std::getline;

/// ------------------------------------------------------------------------ ///
///                                  Desktop                                 ///
/// ------------------------------------------------------------------------ ///
/* #region   */

Desktop::Desktop():
	Prod() {
	this->m_cpnts.clear();
	this->m_price.clear();

	cout << "Enter desktop code: ";
	getline(cin, this->m_code);
	cout << "Enter desktop name: ";
	getline(cin, this->m_name);
	cout << "Enter desktop manufacturer: ";
	getline(cin, this->m_mnft);

	addCpnt();
}

Desktop::Desktop(const string& code, const string& name, const string& mnft, const vector<string>& cpnts, const vector<double>& price) {
	this->m_code = code;
	this->m_name = name;
	this->m_mnft = mnft;

	this->m_cpnts = cpnts;
	this->m_price = price;
}

double Desktop::calcPrice() {
	double price = 0;

	for (int i = 0; i < this->m_cpnts.size(); i++) {
		price += this->m_price[i];
	}

	// VAT
	price *= 1.1;

	return price;
}

void Desktop::addCpnt() {
	int n = 0;
	cout << "Enter number of components: ";
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string name;
		do {
			cout << "\tEnter component name: ";
			getline(cin, name);
		} while (name == "");

		double price;
		do {
			cout << "\tEnter component price: ";
			cin >> price;
			cin.ignore();
		} while (price < 0);

		this->m_cpnts.push_back(name);
		this->m_price.push_back(price);
	}
}

void Desktop::addCpnt(const vector<string>& cpnts, const vector<double>& price) {
	for (int i = 0; i < cpnts.size(); i++) {
		this->m_cpnts.push_back(cpnts[i]);
		this->m_price.push_back(price[i]);
	}
}

void Desktop::rmvCpnt(const string& cpntName) {
	int i = 0;
	for (; i < this->m_cpnts.size(); i++) {
		if (this->m_cpnts[i] == cpntName) {
			break;
		}
	}

	if (i < this->m_cpnts.size()) {
		this->m_cpnts.erase(this->m_cpnts.begin() + i);
		this->m_price.erase(this->m_price.begin() + i);
	}
}

void Desktop::printInfo() {
	cout << "DESKTOP\n";
	cout << "Code: " << this->m_code << "\n";
	cout << "Name: " << this->m_name << "\n";
	cout << "Manufacturer: " << this->m_mnft << "\n";
	cout << "Components: \n";
	for (int i = 0; i < this->m_cpnts.size(); i++) {
		cout << "\t" << this->m_cpnts[i] << ": " << this->m_price[i] << ", ";
		cout << "Price: " << this->m_price[i] << "\n";
	}
	cout << "Total Price: " << this->calcPrice() << "\n";
}

/* #endregion */


/// ------------------------------------------------------------------------ ///
///                                  Laptop                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */

Laptop::Laptop():
	Prod() {
	cout << "Enter laptop code: ";
	getline(cin, this->m_code);
	cout << "Enter laptop name: ";
	getline(cin, this->m_name);
	cout << "Enter laptop manufacturer: ";
	getline(cin, this->m_mnft);
	cout << "Enter laptop factory price: ";
	cin >> this->m_facPrice;
	cin.ignore();
}

Laptop::Laptop(const string& code, const string& name, const string& mnft, const double& facPrice) {
	this->m_code = code;
	this->m_name = name;
	this->m_mnft = mnft;

	this->m_facPrice = facPrice;
}

double Laptop::calcPrice() {
	if (this->m_mnft == "Apple") {
		return this->m_facPrice;
	} else {
		return (this->m_facPrice * 1.1);
	}
}

void Laptop::printInfo() {
	cout << "LAPTOP\n";
	cout << "Code: " << this->m_code << "\n";
	cout << "Name: " << this->m_name << "\n";
	cout << "Manufacturer: " << this->m_mnft << "\n";
	cout << "Factory Price: " << this->m_facPrice << "\n";
	cout << "Selling Price: " << this->calcPrice() << "\n";
}

/* #endregion */


/// ------------------------------------------------------------------------ ///
///                                 ProdList                                 ///
/// ------------------------------------------------------------------------ ///
/* #region   */

ProdList::ProdList() {
	this->m_prods.clear();
}

ProdList::~ProdList() {
	this->m_prods.clear();
}

void ProdList::addProds() {
	cout << "Adding products...\n";

	int n = 0;
	do {
		cout << "How many products do you want to add? ";
		cin >> n;
		cin.ignore();
	} while (n < 1);

	for (int i = 0; i < n; i++) {
		cout << "\nPRODUCT " << i + 1 << "\n";
		int type;
		do {
			cout << "Which type of product do you want to add? (0: Desktop, 1: Laptop): ";
			cin >> type;
			cin.ignore();
		} while ((type < 0) || (type > 1));

		switch (type) {
			case 0: {
				Desktop* newDesktop = new Desktop();
				this->m_prods.push_back(newDesktop);
				break;
			}

			case 1: {
				Laptop* newLaptop = new Laptop();
				this->m_prods.push_back(newLaptop);
				break;
			}

			default: {
				cout << "Invalid type.\n";
				return;
			}
		}
	}
}

void ProdList::queryByMnft() {
	string mnft;

	cout << "Enter manufacturer to query the products: ";
	getline(cin, mnft);

	int counter = 1;
	cout << "===== FOUND =====\n";
	for (int i = 0; i < this->m_prods.size(); i++) {
		if (this->m_prods[i]->getMnft() == mnft) {
			cout << "\n"
				 << counter << ". ";
			counter++;

			this->m_prods[i]->printInfo();
		}
	}
	cout << "\n=================\n";
}

void ProdList::sortByPriceDes() {
	for (int i = 0; i < this->m_prods.size(); i++) {
		for (int j = (i + 1); j < this->m_prods.size(); j++) {
			if (this->m_prods[i]->calcPrice() < this->m_prods[j]->calcPrice()) {
				Prod* temp = this->m_prods[i];
				this->m_prods[i] = this->m_prods[j];
				this->m_prods[j] = temp;
			} else if (this->m_prods[i]->calcPrice() == this->m_prods[j]->calcPrice()) {
				// Sort by manufacturer name, ascending
				if (this->m_prods[i]->getMnft() > this->m_prods[j]->getMnft()) {
					Prod* temp = this->m_prods[i];
					this->m_prods[i] = this->m_prods[j];
					this->m_prods[j] = temp;
				}
			}
		}
	}
}

double ProdList::calcTotalPrice() {
	double totalPrice = 0;

	for (int i = 0; i < this->m_prods.size(); i++) {
		totalPrice += this->m_prods[i]->calcPrice();
	}

	return totalPrice;
}

void ProdList::printList() {
	cout << "\n=== PRODUCT LIST === \n";
	
	for (int i = 0; i < this->m_prods.size(); i++) {
		cout << "\n"
			 << (i + 1) << ". ";
		this->m_prods[i]->printInfo();
	}
	
	cout << "\n\nTotal Price: " << this->calcTotalPrice() << "\n";
	cout << "====================\n";
}

/* #endregion */