#include "ctg.h"


/// ------------------------------------------------------------------------ ///
///                                    Ctg                                   ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
//
Ctg::Ctg() {
	this->_id = 0;
	this->_name = "";
}

//
Ctg::Ctg(Ctg const &other) {
	this->_id = other._id;
	this->_name = other._name;
}

//
Ctg::Ctg(int const &id, string const &name) {
	this->_id = id;
	this->_name = name;
}

//
Ctg::~Ctg() {
	this->_id = 0;
	this->_name = "";
}
/* #endregion */

/// ---------------------------------- get --------------------------------- ///
// Returns the ID of this category
int Ctg::get_id() {
	return this->_id;
}

// Returns the name of this category
string Ctg::get_name() {
	return this->_name;
}

/// ---------------------------------- set --------------------------------- ///
// Set the ID for this category
void Ctg::set_id(int const &id) {
	this->_id = id;
}

// Set the name for this category
void Ctg::set_name(string const &name) {
	this->_name = name;
}
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                  CtgVct                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
//
CtgVct::CtgVct() {
	this->_vct.reserve(1);
}

//
CtgVct::CtgVct(CtgVct const &other) {
	this->_vct.reserve(other._vct.size());
	
	for (int i = 0; i < other._vct.size(); i++) {
		this->_vct.push_back(other._vct[i]);
	}
}

//
CtgVct::~CtgVct() {
	this->_vct.clear();
}

/// ---------------------------------- get --------------------------------- ///
// Returns the whole vector
vector<Ctg> CtgVct::get_vct() {
	return this->_vct;
}

// Returns a vector of Ctg objects with the given ID
Ctg CtgVct::get_ctg(int const &ctg_id) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == ctg_id) {
			return this->_vct[i];
		}
	}
	
	return Ctg();
}

/// ---------------------------------- set --------------------------------- ///
// Set a Ctg object with the given ID in the vector
void CtgVct::set_ctg(int const &ctg_id, Ctg const &c) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == ctg_id) {
			this->_vct[i] = Ctg(c);
			return;
		}
	}
}

// Add a new Ctg object to the vector
void CtgVct::add_ctg(Ctg const &c) {
	this->_vct.push_back(Ctg(c));
}
/* #endregion */