#include <iostream>
#include "point.h"

/// ------------------------------------------------------------------------ ///
///                                   Point                                  ///
/// ------------------------------------------------------------------------ ///

/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
Point::Point() {
	this->_x = 0;
	this->_y = 0;
}

Point::Point(int const &x, int const &y) {
	this->_x = x;
	this->_y = y;
}

Point::Point(Point const &other) {
	this->_x = other._x;
	this->_y = other._y;
}
/* #endregion */

/// -------------------------------- get/set ------------------------------- ///
/* #region   */
int Point::getX() {
	return this->_x;
}

int Point::getY() {
	return this->_y;
}


void Point::setX(int const &x) {
	this->_x = x;
}

void Point::setY(int const &y) {
	this->_y = y;
}
/* #endregion */

/// --------------------------------- print -------------------------------- ///
void Point::print() {
	std::cout << "(" << this->_x << ", " << this->_y << ")";
}


/// ------------------------------------------------------------------------ ///
///                                 PointVct                                 ///
/// ------------------------------------------------------------------------ ///

/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */

PointVct::PointVct() {
	this->_vt.reserve(1);
}

PointVct::PointVct(PointVct const &other) {
	for (int i = 0; i < other._vt.size(); i++) {
		this->_vt.push_back(other._vt[i]);
	}
}

PointVct::PointVct(vector<int> const &vt1, vector<int> const &vt2) {
	for (int i = 0; i < vt1.size(); i++) {
		this->_vt.push_back(Point(vt1[i], vt2[i]));
	}
}

PointVct::~PointVct() {
	this->_vt.clear();
}
/* #endregion */

/// -------------------------------- get/set ------------------------------- ///
/* #region   */
Point PointVct::getData(int const &index) {
	return this->_vt[index];
}

int PointVct::getSize() {
	return this->_vt.size();
}


void PointVct::setData(int const &index, int const &data) {
	this->_vt[index].setX(data);
}

void PointVct::addData(int const &index, int const &data) {
	this->_vt.push_back(Point(data, data));
}
/* #endregion */

/// --------------------------------- print -------------------------------- ///
void PointVct::print() {
	for (int i = 0; i < this->_vt.size(); i++) {
		this->_vt[i].print();
	}
}