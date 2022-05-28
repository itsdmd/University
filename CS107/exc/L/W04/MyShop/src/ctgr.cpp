#include "ctgr.h"


/// ------------------------------------------------------------------------ ///
///                                    Ctgr                                   ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
//
Ctgr::Ctgr() {
	this->_id = 0;
	this->_name = "";
}

//
Ctgr::Ctgr(Ctgr const &other) {
	this->_id = other._id;
	this->_name = other._name;
}

//
Ctgr::Ctgr(int const &id, string const &name) {
	this->_id = id;
	this->_name = name;
}

//
Ctgr::~Ctgr() {
	this->_id = 0;
	this->_name = "";
}
/* #endregion */

/// ---------------------------------- get --------------------------------- ///
// Returns the ID of this category
int Ctgr::get_id() {
	return this->_id;
}

// Returns the name of this category
string Ctgr::get_name() {
	return this->_name;
}

/// ---------------------------------- set --------------------------------- ///
// Set the ID for this category
void Ctgr::set_id(int const &id) {
	this->_id = id;
}

// Set the name for this category
void Ctgr::set_name(string const &name) {
	this->_name = name;
}
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                  CtgrVct                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
//
CtgrVct::CtgrVct() {
	this->_vct.reserve(1);
}

//
CtgrVct::CtgrVct(CtgrVct const &other) {
	this->_vct.reserve(other._vct.size());
	
	for (int i = 0; i < other._vct.size(); i++) {
		this->_vct.push_back(other._vct[i]);
	}
}

//
CtgrVct::~CtgrVct() {
	this->_vct.clear();
}

/// ---------------------------------- get --------------------------------- ///
// Returns the whole vector
vector<Ctgr> CtgrVct::get_vct() {
	return this->_vct;
}

// Returns a vector of Ctgr objects with the given ID
Ctgr CtgrVct::get_ctgr(int const &ctgr_id) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == ctgr_id) {
			return this->_vct[i];
		}
	}
	
	return Ctgr();
}

/// ---------------------------------- set --------------------------------- ///
// Set a Ctgr object with the given ID in the vector
void CtgrVct::set_ctgr(int const &ctgr_id, Ctgr const &c) {
	for (int i = 0; i < this->_vct.size(); i++) {
		if (this->_vct[i].get_id() == ctgr_id) {
			this->_vct[i] = Ctgr(c);
			return;
		}
	}
}

// Add a new Ctgr object to the vector
void CtgrVct::add_ctgr(Ctgr const &c) {
	this->_vct.push_back(Ctgr(c));
}
/* #endregion */