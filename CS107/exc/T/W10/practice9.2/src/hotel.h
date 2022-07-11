#ifndef HOTEL_H
#define HOTEL_H

#include <vector>

using std::vector;

class Room {
	protected:
		float m_unit = 0;				// unit price
		int m_days = 0;

	public:
		virtual void input();
		virtual float calcRent();
};

class TypeA: public Room {
	private:
		float m_srv = 0;			   // service fee

	public:
		TypeA();
		void input() override;
		float calcRent() override;
};

class TypeB: public Room {
	public:
		TypeB();
		friend float TypeA::calcRent();
};

class TypeC: public Room {
	public:
		TypeC();
};

class Hotel {
	protected:
		vector<Room*> m_rooms;

	public:
		void input();
		double totalRent();
};

#endif