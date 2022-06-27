#include "cine.h"

#include <algorithm>
#include <cmath>

/// ------------------------------------------------------------------------ ///
///                                  Cinema                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/// --------------------------------- Cstr --------------------------------- ///

Cinema::Cinema() {
	this->m_m = 0;
	this->m_n = 0;
	this->m_price = 0;
	this->m_booked.resize(0);
}

Cinema::Cinema(const int m, const int n) {
	this->m_m = m;
	this->m_n = n;
	this->m_price = 0;
	this->m_booked.resize(0);
}

/// --------------------------------- Price -------------------------------- ///

float Cinema::seatPrice(const int m, const int n) const {
	return (this->m_price - (this->m_discount * abs((this->m_m / 2) - m)));
}

double Cinema::totalPrice() const {
	double total = 0;

	for (int i = 0; i < this->m_booked.size(); i++) {
		total += this->seatPrice(this->m_booked[i][1], this->m_booked[i][2]);
	}

	return total;
}

/// --------------------------------- Seat --------------------------------- ///

bool Cinema::seatAvailable(const int day, const int m, const int n) const {
	if (((n < 0) || (n > this->m_n)) || ((m < 0) || (m > this->m_m))) {
		return false;
	}

	vector<int> target = {day, m, n};

	if (std::find(this->m_booked.begin(), this->m_booked.end(), target) != this->m_booked.end()) {
		return false;
	}
	return true;
}

// Monday = 0, Tuesday = 1, etc.
void Cinema::bookSeat(const int day, const int m, const int n) {
	if (((n < 0) || (n > this->m_n)) || ((m < 0) || (m > this->m_m))) {
		return;
	}

	if (seatAvailable(day, m, n)) {
		vector<int> booking = {day, m, n};
		this->m_booked.push_back(booking);

		return;
	}

	return;
}

/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                 VIPCinema                                ///
/// ------------------------------------------------------------------------ ///

float VIPCinema::seatPrice(const int day, const int m, const int n) const {
	float dayDiscount = 0;

	if (day == 3) {
		dayDiscount = 0.2;
	}

	return (Cinema::seatPrice(m, n) * (1.0f - dayDiscount));
}