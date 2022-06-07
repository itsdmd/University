#pragma once

class Student {
private:
	char *name;
	float math;
	float lit;
	
public:
	Student();
	Student(const char *name, float math, float lit);
	Student(const Student& other);
	~Student();
	
	Student& operator = (const Student& other);
	void setSize(int const &size);
	
	void setName(const char *name);
	void setMath(float const &math);
	void setLit(float const &lit);
	
	const char *getName();
	float getMath();
	float getLit();
	
	void prfloat();
};