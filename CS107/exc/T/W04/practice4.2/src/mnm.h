#pragma once

#include <iostream>


class Mnm {
private:
	float coef;
	int expo;

public:
	Mnm();
	Mnm(float const &c, int const &e);
	Mnm(const Mnm& m);
	~Mnm();
	
	Mnm operator * (const Mnm& other);
	bool operator > (const Mnm& other);
	bool operator < (const Mnm& other);
	bool operator >= (const Mnm& other);
	bool operator <= (const Mnm& other);
	bool operator == (const Mnm& other);
	bool operator != (const Mnm& other);
	Mnm& operator = (const Mnm& other);
	Mnm& operator *= (const Mnm& other);
	Mnm& operator ++ ();
	Mnm operator ++ (int);
	Mnm& operator -- ();
	Mnm operator -- (int);
	Mnm operator ! ();
	friend std::ostream& operator << (std::ostream& os, const Mnm& m);
	friend std::istream& operator >> (std::istream& is, Mnm& m);
	
	float getCoef();
	int getExpo();
	
	void setCoef(float const &c);
	void setExpo(int const &e);
	
	float evaluate(float const &x);
	Mnm derive();
	Mnm mul(Mnm m);
};