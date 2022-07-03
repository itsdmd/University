#ifndef CINEMA_H
#define CINEMA_H

#include <vector>

using std::vector;

class Cinema {
protected:
	int m_m;							// Row
	int m_n;							// Column
	float m_price;						// Price of the middle row seats
	const float m_discount = 0.5;		// Discount ($) per row from the middle
	vector<vector<int>> m_booked;		// Booked seats. Each element is a booking, each booking is a vector with format ([day], [m], [n]).

public:
	Cinema();
	Cinema(const int m, const int n);

	float seatPrice(const int m, const int n) const;
	double totalPrice() const;

	bool seatAvailable(const int day, const int m, const int n) const;
	void bookSeat(const int day, const int m, const int n);
};

class StandardCinema: public Cinema {
public:
	StandardCinema():
		Cinema() { this->m_price = 10; };
	StandardCinema(const int m, const int n):
		Cinema(m, n) { this->m_price = 10; };
};

class VIPCinema: public Cinema {
public:
	VIPCinema():
		Cinema() { this->m_price = 15; };
	VIPCinema(const int m, const int n):
		Cinema(m, n) { this->m_price = 15; };

	float seatPrice(const int day, const int m, const int n) const;
};

#endif