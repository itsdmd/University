#pragma once

#include <iostream>

using std::ostream;
using std::istream;


class Time {
private:
	int h;
	int m;
	int s;

public:
	Time();
	Time(int const &hour, int const &minute, int const &second);
	Time(int const &seconds);
	Time(Time const &other);
	
	Time operator + (int const &seconds);
	bool operator > (Time const &other) const;
	bool operator < (Time const &other) const;
	bool operator >= (Time const &other) const;
	bool operator <= (Time const &other) const;
	bool operator == (Time const &other) const;
	bool operator != (Time const &other) const;
	Time& operator ++ ();
	Time operator ++ (int);
	friend ostream& operator << (ostream & os, Time const &m);
	friend istream& operator >> (istream & is, Time & m);
	
	
	Time& setTime(int hour, int minute, int second);
	Time& setHour(int hour);
	Time& setMinute(int minute);
	Time& setSecond(int second);
	
	Time& addSecs(int seconds);
	int difInSecs(Time const &other) const;
	
private:
	int getAbsSec() const;
	
	int toTimeHour(int seconds) const;
	int toTimeMinute(int seconds) const;
	int toTimeSecond(int seconds) const;
	
	Time& setTimeFromAbsSec(int seconds);
};