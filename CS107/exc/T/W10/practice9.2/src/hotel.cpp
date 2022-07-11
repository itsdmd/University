#include "hotel.h"

#include <iostream>

using std::cin;
using std::cout;

/// ------------------------------------------------------------------------ ///
///                                   Room                                   ///
/// ------------------------------------------------------------------------ ///
void Room::input() {
	cout << "Number of renting days: ";
	cin >> this->m_days;
}

float Room::calcRent() {
	return (this->m_unit * this->m_days);
}

TypeA::TypeA() {
	this->m_unit = 300;
}

void TypeA::input() {
	Room::input();

	cout << "Service fee: ";
	cin >> this->m_srv;
}

float TypeA::calcRent() {
	float res = this->m_srv;

	if (this->m_days > 10) {
		res += ((this->m_unit * 10)
				+ (this->m_unit * (this->m_days - 10)) * 0.9);
	} else {
		res += Room::calcRent();
	}

	return res;
}

TypeB::TypeB() {
	this->m_unit = 200;
}

TypeC::TypeC() {
	this->m_unit = 100;
}

/// ------------------------------------------------------------------------ ///
///                                   Hotel                                  ///
/// ------------------------------------------------------------------------ ///
void Hotel::input() {
	int n;

	cout << "Number of room: ";
	cin >> n;

	this->m_rooms.clear();
	this->m_rooms.reserve(n);


	for (int i = 0; i < n; ++i) {
		Room* room;

		cout << "Room " << i << ":\n";

		int type;
		cout << "Enter room type (A = 0, B = 1, C = 2): ";
		cin >> type;

		switch (type) {
			case 0:
				room = new TypeA();
				break;

			case 1:
				room = new TypeB();
				break;

			case 2:
				room = new TypeC();
				break;

			default:
				cout << "ERROR: Invalid type of room.\n";
				continue;
				break;
		}

		room->input();
		this->m_rooms.push_back(room);
	}
}

double Hotel::totalRent() {
	double total = 0;

	for (auto room : this->m_rooms) {
		total += room->calcRent();
	}

	return total;
}