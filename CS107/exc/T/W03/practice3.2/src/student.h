#pragma once

class Student {
private:
	char *name;
	int math;
	int lit;
	
public:
	Student();
	Student(const char *name, int math, int lit);
	Student(const Student& other);
	~Student();
	
	void setName(const char *name);
	void setMath(int const &math);
	void setLit(int const &lit);
	
	const char *getName();
	int getMath();
	int getLit();
	
	void print();
};