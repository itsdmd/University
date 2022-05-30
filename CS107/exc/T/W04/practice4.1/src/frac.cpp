#include <iostream>
#include <numeric> // std::gcd
#include "frac.h"

using std::cout;
using std::cin;


/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
Frac::Frac() {
	this->num = 0;
	this->den = 1;
}

Frac::Frac(int n, int d) {
	this->num = n;
	this->den = d;
}

Frac::Frac(Frac const &f) {
	this->num = f.num;
	this->den = f.den;
}

Frac::~Frac() {
	this->num = 0;
	this->den = 1;
}
/* #endregion */

/// ------------------------------- Operators ------------------------------ ///
/* #region   */
/* #region   */
Frac Frac::operator + (const Frac& other) {
	Frac result;
	result.setNum((this->num * other.den) + (this->den * other.num));
	result.setDen((this->den * other.den));
	
	return result;
}

Frac Frac::operator * (const Frac& other) {
	Frac result;
	result.setNum(this->num * other.num);
	result.setDen(this->den * other.den);
	
	return result;
}
/* #endregion */


/* #region   */
bool Frac::operator > (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d > other_d);
}

bool Frac::operator < (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d < other_d);
}

bool Frac::operator >= (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d >= other_d);
}

bool Frac::operator <= (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d <= other_d);
}

bool Frac::operator == (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d == other_d);
}

bool Frac::operator != (const Frac& other) {
	double this_d = (double)this->num / (double)this->den;
	double other_d = (double)other.num / (double)other.den;
	
	return (this_d != other_d);
}
/* #endregion */


/* #region   */
Frac& Frac::operator = (const Frac& other) {
	this->num = other.num;
	this->den = other.den;
	
	return *this;
}

Frac& Frac::operator += (const Frac& other) {
	this->num = (this->num * other.num) + (this->den * other.num);
	this->den = (this->den * other.den);
	
	return *this;
}

Frac& Frac::operator -= (const Frac& other) {
	this->num = (this->num * other.num) - (this->den * other.num);
	this->den = (this->den * other.den);
	
	return *this;
}

Frac& Frac::operator *= (const Frac& other) {
	this->num = this->num * other.num;
	this->den = this->den * other.den;
	
	return *this;
}
/* #endregion */


/* #region   */
Frac& Frac::operator ++ () {
	this->num += this->den;
	
	return *this;
}

Frac Frac::operator ++ (int) {
	Frac result(*this);
	
	this->num += this->den;
	
	return result;
}

Frac& Frac::operator -- () {
	this->num -= this->den;
	
	return *this;
}

Frac Frac::operator -- (int) {
	Frac result(*this);
	
	this->num -= this->den;
	
	return result;
}
/* #endregion */


/* #region   */
std::ostream& operator << (std::ostream& os, const Frac& f) {
	if (f.num == 0) {
		os << "0";
	} else if (f.den == 1) {
		os << f.num;
	} else {
		os << f.num << "/" << f.den;
	}
	
	return os;
}

std::istream& operator >> (std::istream& is, Frac& f) {
	is >> f.num >> f.den;
	
	return is;
}
/* #endregion */
/* #endregion */


int Frac::getNum() {
	return this->num;
}

int Frac::getDen() {
	return this->den;
}

void Frac::setNum(int const &n) {
	this->num = n;
}

void Frac::setDen(int const &d) {
	this->den = d;
}

Frac Frac::reduce() {
	int gcd = std::gcd(num, den);
	
	num /= gcd;
	den /= gcd;
	
	return *this;
}