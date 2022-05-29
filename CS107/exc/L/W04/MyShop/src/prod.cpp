#include <algorithm>	// std::transform

#include "prod.h"


/// ------------------------------------------------------------------------ ///
///                                   Prod                                   ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
//
Prod::Prod() {
	this->_id = 0;
	this->_name = "";
	this->_price = 0;
	this->_ctgr = 0;
}

//
Prod::Prod(int const &id, string const &name, long const &price, int const &ctgr) {
	this->_id = id;
	this->_name = name;
	this->_price = price;
	this->_ctgr = ctgr;
}

//
Prod::Prod(Prod const &other) {
	this->_id = other._id;
	this->_name = other._name;
	this->_price = other._price;
	this->_ctgr = other._ctgr;
}

//
Prod::~Prod() {
	this->_id = 0;
	this->_name = "";
	this->_price = 0;
	this->_ctgr = 0;
}
/* #endregion */

/// ---------------------------------- get --------------------------------- ///
/* #region   */
// Returns the ID of this prod
int Prod::get_id() {
	return this->_id;
}

// Returns the name of this prod
string Prod::get_name() {
	return this->_name;
}

// Returns the price of this prod
long Prod::get_price() {
	return this->_price;
}

// Returns the category ID of this prod
int Prod::get_ctgr() {
	return this->_ctgr;
}
/* #endregion */

/// ---------------------------------- set --------------------------------- ///
/* #region   */
// Set the ID for this prod
void Prod::set_id(int const &id) {
	this->_id = id;
}

// Set the name for this prod
void Prod::set_name(string const &name) {
	this->_name = name;
}

// Set the price for this prod
void Prod::set_price(long const &price) {
	this->_price = price;
}

// Set the category ID for this prod
void Prod::set_ctgr(int const &ctgr) {
	this->_ctgr = ctgr;
}
/* #endregion */
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                  ProdVct                                 ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
//
ProdVct::ProdVct() {
	this->_vct.reserve(1);
}

//
ProdVct::ProdVct(ProdVct const &other) {
	this->_vct.reserve(other._vct.size());
	
	for (int i = 0; i < other._vct.size(); i++) {
		this->_vct.push_back(other._vct[i]);
	}
}

//
ProdVct::~ProdVct() {
	this->_vct.clear();
}
/* #endregion */

/// ---------------------------------- get --------------------------------- ///
/* #region   */
// Returns the whole vector
vector<Prod> ProdVct::get_vct() {
	return this->_vct;
}

// Returns the vector that contains products that contain a given keyword in their name
vector<Prod> ProdVct::get_vct(string keyword) {
	vector<Prod> res;
	
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), ::tolower);
	
	for (Prod &p : this->_vct) {
		string prod_name = p.get_name();
		std::transform(prod_name.begin(), prod_name.end(), prod_name.begin(), ::tolower);
		
		if (prod_name.find(keyword) != string::npos) {
			res.push_back(p);
		}
	}
	
	return res;
}

// Returns the vector that contains products that's within a given price range
vector<Prod> ProdVct::get_vct(long const &min_price, long const &max_price) {
	vector<Prod> res;
	
	for (Prod &p : this->_vct) {
		if ((p.get_price() >= min_price) && (p.get_price() <= max_price)) {
			res.push_back(p);
		}
	}
	
	return res;
}

// Returns a Prod object that has a given ID
Prod ProdVct::get_prod(int const &p_id) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == p_id) {
			return this->_vct[i];
		}
	}
	
	return Prod();
}

// Returns a Prod object that has a given name
Prod ProdVct::get_prod(string const &p_name) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_name() == p_name) {
			return this->_vct[i];
		}
	}
	
	return Prod();
}
/* #endregion */

/// ---------------------------------- set --------------------------------- ///
/* #region   */
// Set the value for a Prod object that has a given ID in the vector
void ProdVct::set_prod(int const &p_id, Prod const &p) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == p_id) {
			this->_vct[i] = Prod(p);
			
			return;
		}
	}
}

// Set the value for a Prod object that has a given name in the vector
void ProdVct::set_prod(string const &p_name, Prod const &p) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_name() == p_name) {
			this->_vct[i] = Prod(p);
			
			return;
		}
	}
}

// Add a new Prod object to the vector
void ProdVct::add_prod(Prod const &p) {
	this->_vct.push_back(p);
}
/* #endregion */
/* #endregion */