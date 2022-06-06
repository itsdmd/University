#include "time.h"


/// ------------------------------------------------------------------------ ///
///                                 Cstr/Dstr                                ///
/// ------------------------------------------------------------------------ ///
/* #region   */
Time::Time() {
	this->h = 0;
	this->m = 0;
	this->s = 0;
}

Time::Time(int const &hour, int const &minute, int const &second) {
	this->setTime(hour, minute, second);
}

Time::Time(int const &seconds) {
	this->setTimeFromAbsSec(seconds);
}

Time::Time(const Time& other) {
	this->h = other.h;
	this->m = other.m;
	this->s = other.s;
}
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                 Operators                                ///
/// ------------------------------------------------------------------------ ///
/* #region   */
Time Time::operator + (const int& seconds) {
	Time res = (this->getAbsSec() + seconds);
	
	return res;
}

/* #region   */
bool Time::operator > (const Time& other) const {
	return (this->getAbsSec() > other.getAbsSec());
}

bool Time::operator < (const Time& other) const {
	return (this->getAbsSec() < other.getAbsSec());
}

bool Time::operator >= (const Time& other) const {
	return (this->getAbsSec() >= other.getAbsSec());
}

bool Time::operator <= (const Time& other) const {
	return (this->getAbsSec() <= other.getAbsSec());
}

bool Time::operator == (const Time& other) const {
	return (this->getAbsSec() == other.getAbsSec());
}

bool Time::operator != (const Time& other) const {
	return (this->getAbsSec() != other.getAbsSec());
}
/* #endregion */

Time& Time::operator ++ () {
	this->addSecs(1);
	return *this;
}

Time Time::operator ++ (int) {
	Time temp = *this;
	this->addSecs(1);
	return temp;
}

/* #region   */
ostream& operator << (ostream& stream, const Time& t) {
	if (t.h < 10) {
		stream << "0";
	}
	stream << t.h << ":";
	
	if (t.m < 10) {
		stream << "0";
	}
	stream << t.m << ":";
	
	if (t.s < 10) {
		stream << "0";
	}
	stream << t.s;
	
	
	return stream;
}

istream& operator >> (istream& stream, Time& t) {
	int hour, min, sec;
	bool valid = false;
	
	while (!valid) {
		std::cout << "Enter time: ";
		stream >> hour >> min >> sec;
		
		try {
			t.setTime(hour, min, sec);
		}
		
		catch (...) {
			std::cout << "Invalid time. Try again.\n";
		}
		
		valid = true;
	}
	
	
	return stream;
}

/* #region   */
Time& Time::setTime(int hour, int minute, int second) {
	if (hour < 0 || hour > 23) {
		throw std::invalid_argument("Invalid hour");
	} else this->h = hour;
	
	if (minute < 0 || minute > 59) {
		throw std::invalid_argument("Invalid minute");
	} else this->m = minute;
	
	if (second < 0 || second > 59) {
		throw std::invalid_argument("Invalid second");
	} else this->s = second;
	
	
	return *this;
}

Time& Time::setHour(int hour) {
	if (hour < 0 || hour > 23) {
		throw std::invalid_argument("Invalid hour");
	} else this->h = hour;
	
	
	return *this;
}

Time& Time::setMinute(int minute) {
	if (minute < 0 || minute > 59) {
		throw std::invalid_argument("Invalid minute");
	} else this->m = minute;
	
	
	return *this;
}

Time& Time::setSecond(int second) {
	if (second < 0 || second > 59) {
		throw std::invalid_argument("Invalid second");
	} else this->s = second;
	
	
	return *this;
}
/* #endregion */
/* #endregion */
/* #endregion */

/// ------------------------------------------------------------------------ ///
///                                   Algos                                  ///
/// ------------------------------------------------------------------------ ///
/* #region   */
/* #region   */
Time& Time::addSecs(int seconds) {
	this->setTimeFromAbsSec(this->getAbsSec() + seconds);
	
	return *this;
}

int Time::difInSecs(const Time& other) const {
	return (this->getAbsSec() - other.getAbsSec());
}
/* #endregion */

/* #region   */
int Time::getAbsSec() const {
	return ((this->h * 3600) + (this->m * 60) + this->s);
}

int Time::toTimeHour(int seconds) const {
	return (seconds / 3600);
}

int Time::toTimeMinute(int seconds) const {
	return ((seconds % 3600) / 60);
}

int Time::toTimeSecond(int seconds) const {
	return (seconds % 60);
}

Time& Time::setTimeFromAbsSec(int seconds) {
	this->h = (seconds / 3600);
	this->m = ((seconds % 3600) / 60);
	this->s = ((seconds % 3600) % 60);
	
	return *this;
}
/* #endregion */
/* #endregion */