#include <cmath>

#include "mnm.h"

using std::cout;
using std::cin;


/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
Mnm::Mnm() {
	this->coef = 0;
	this->expo = 0;
}

Mnm::Mnm(float const &c, int const &e) {
	this->coef = c;
	this->expo = e;
}

Mnm::Mnm(const Mnm& m) {
	this->coef = m.coef;
	this->expo = m.expo;
}

Mnm::~Mnm() {
	this->coef = 0;
	this->expo = 0;
}
/* #endregion */

/// ------------------------------- Operators ------------------------------ ///
/* #region   */
Mnm Mnm::operator * (const Mnm& other) {
	Mnm m;
	m.coef = (this->coef * other.coef);
	m.expo = (this->expo + other.expo);
	return m;
}

/* #region   */
bool Mnm::operator > (const Mnm& other) {
	return (this->expo > other.expo);
	
	if (this->expo == other.expo) {
		return (this->coef > other.coef);
	}
	else {
		return false;
	}
}

bool Mnm::operator < (const Mnm& other) {
	return (this->expo < other.expo);
	
	if (this->expo == other.expo) {
		return (this->coef < other.coef);
	}
	else {
		return false;
	}
}

bool Mnm::operator >= (const Mnm& other) {
	return (this->expo >= other.expo);
	
	if (this->expo == other.expo) {
		return (this->coef >= other.coef);
	}
	else {
		return false;
	}
}

bool Mnm::operator <= (const Mnm& other) {
	return (this->expo <= other.expo);
	
	if (this->expo == other.expo) {
		return (this->coef <= other.coef);
	}
	else {
		return false;
	}
}

bool Mnm::operator == (const Mnm& other) {
	return (this->expo == other.expo);
	
	if (this->expo == other.expo) {
		return (this->coef == other.coef);
	}
	else {
		return false;
	}
}
/* #endregion */


/* #region   */
Mnm& Mnm::operator = (const Mnm& other) {
	this->coef = other.coef;
	this->expo = other.expo;
	
	return *this;
}

Mnm& Mnm::operator *= (const Mnm& other) {
	this->coef *= other.coef;
	this->expo += other.expo;
	
	return *this;
}

// Increment the value of exponent
Mnm& Mnm::operator ++ () {
	this->expo += 1;
	
	return *this;
}

Mnm Mnm::operator ++ (int) {
	Mnm m;
	
	m.coef = this->coef;
	m.expo = this->expo + 1;
	
	return m;
}

// Decrement the value of exponent
Mnm& Mnm::operator -- () {
	this->expo -= 1;
	
	return *this;
}

Mnm Mnm::operator -- (int) {
	Mnm m;
	
	m.coef = this->coef;
	m.expo = this->expo - 1;
	
	return m;
}

// Derive
Mnm& Mnm::operator ! () {
	this->coef *= this->expo;
	this->expo -= 1;
	
	return *this;
}
/* #endregion */

/* #region   */
std::ostream& operator << (std::ostream& os, const Mnm& m) {
	os << m.coef << "x^" << m.expo;
	
	return os;
}

std::istream& operator >> (std::istream& is, Mnm& m) {
	is >> m.coef >> m.expo;
	
	return is;
}
/* #endregion */
/* #endregion */



/// -------------------------------- get/set ------------------------------- ///
/* #region   */
/* #region   */
float Mnm::getCoef() {
	return this->coef;
}

int Mnm::getExpo() {
	return this->expo;
}
/* #endregion */

/* #region   */
void Mnm::setCoef(float const &c) {
	this->coef = c;
}

void Mnm::setExpo(int const &e) {
	this->expo = e;
}
/* #endregion */
/* #endregion */


/// --------------------------------- algos -------------------------------- ///
/* #region   */
float Mnm::evaluate(float const &x) {
	return (this->coef * pow(x, this->expo));
}

Mnm Mnm::derive() {
	Mnm d;
	
	d.setCoef(this->coef * this->expo);
	d.setExpo(this->expo - 1);
	
	return d;
}
/* #endregion */