#pragma once

#include <iostream>

class Frac {
private:
	int num;
	int den;

public:
	Frac();
	Frac(int n, int d);
	Frac(const Frac& f);
	~Frac();
	
	Frac operator + (const Frac& other);
	Frac operator * (const Frac& other);
	bool operator > (const Frac& other);
	bool operator < (const Frac& other);
	bool operator >= (const Frac& other);
	bool operator <= (const Frac& other);
	bool operator == (const Frac& other);
	bool operator != (const Frac& other);
	Frac& operator = (const Frac& other);
	Frac& operator += (const Frac& other);
	Frac& operator -= (const Frac& other);
	Frac& operator *= (const Frac& other);
	Frac& operator ++ ();
	Frac operator ++ (int);
	Frac& operator -- ();
	Frac operator -- (int);
	operator int() const { return (this->num / this->den); };
	operator float() const { return ((float)this->num / (float)this->den); };
	friend std::ostream& operator << (std::ostream& os, const Frac& f);
	friend std::istream& operator >> (std::istream& is, Frac& f);
	
	int getNum();
	int getDen();
	
	void setNum(int const &n);
	void setDen(int const &d);
	
	Frac reduce();
};