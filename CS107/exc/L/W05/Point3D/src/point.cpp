#include <cmath>
#include <iostream>

#include "point.h"
#include "rng.h"

/// ------------------------------------------------------------------------ ///
///                                  Point2D                                 ///
/// ------------------------------------------------------------------------ ///

/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
Point2D::Point2D() {
	this->_x = 0;
	this->_y = 0;
}

Point2D::Point2D(double const &x, double const &y) {
	this->_x = x;
	this->_y = y;
}

Point2D::Point2D(int const &min, int const &max) {
	this->_x = rng(min, max);
	this->_y = rng(min, max);
}

Point2D::~Point2D() {
	// Nothing to do here
}
/* #endregion */


/// -------------------------------- get/set ------------------------------- ///
/* #region   */
double Point2D::getX() const {
	return this->_x;
}

double Point2D::getY() const {
	return this->_y;
}


void Point2D::setX(double const &x) {
	this->_x = x;
}

void Point2D::setY(double const &y) {
	this->_y = y;
}

void Point2D::setXY(double const &x, double const &y) {
	this->_x = x;
	this->_y = y;
}
/* #endregion */


/// --------------------------------- Algos -------------------------------- ///
/* #region   */
double Point2D::distance(Point2D const &p) const {
	return sqrt(pow((this->_x - p.getX()), 2) + pow((this->_y - p.getY()), 2));
}


void Point2D::print() const {
	std::cout << "(" << this->_x << ", " << this->_y << ")";
}
/* #endregion */
/* #endregion */




/// ------------------------------------------------------------------------ ///
///                                  Point3D                                 ///
/// ------------------------------------------------------------------------ ///

/* #region   */
/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
Point3D::Point3D() {
	this->_x = 0;
	this->_y = 0;
	this->_z = 0;
}

Point3D::Point3D(double const &x, double const &y, double const &z) {
	this->_x = x;
	this->_y = y;
	this->_z = z;
}

Point3D::Point3D(int const &min, int const &max) {
	this->_x = rng(min, max);
	this->_y = rng(min, max);
	this->_z = rng(min, max);
}

Point3D::~Point3D() {
	// Nothing to do here
}
/* #endregion */


/// -------------------------------- get/set ------------------------------- ///
/* #region   */
//TODO: Find a way to access X, Y
double Point3D::getZ() const {
	return this->_z;
}

void Point3D::setZ(double const &z) {
	this->_z = z;
}

void Point3D::setXYZ(double const &x, double const &y, double const &z) {
	this->setX(x);
	this->setY(y);
	this->_z = z;
}
/* #endregion */


/// --------------------------------- Algos -------------------------------- ///
/* #region   */
double Point3D::distance(Point3D const &p) const {
	return sqrt(pow((this->_x - p.getX()), 2) + pow((this->_y - p.getY()), 2) + pow((this->_z - p.getZ()), 2));
}

void Point3D::print() const {
	std::cout << "(" << this->_x << ", " << this->_y << ", " << this->_z << ")";
}
/* #endregion */
/* #endregion */