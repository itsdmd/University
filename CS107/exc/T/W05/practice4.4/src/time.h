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
	Time(int const &abs_sec);
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
	
	int getHour() const;
	int getMinute() const;
	int getSecond() const;
	int getAbsSec() const;
	
	Time& setHour(int hour);
	Time& setMinute(int minute);
	Time& setSecond(int second);
	Time& setTime(int hour, int minute, int second);
	Time& setTimeFromAbsSec(int abs_sec);
	
	Time& addSecs(int seconds);
	int difInSecs(Time const &other) const;
	
private:
	int toTimeHour(int abs_sec) const;
	int toTimeMinute(int abs_sec) const;
	int toTimeSecond(int abs_sec) const;
};