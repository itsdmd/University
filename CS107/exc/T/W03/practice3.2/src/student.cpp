#include <cstring>	// std::strcpy
#include <iostream>
#include "student.h"

using std::cout;
using std::cin;
using std::strcpy;


/// ------------------------------- Cstr/Dstr ------------------------------ ///
Student::Student() {
	this->name = new char[1];
	this->name[0] = '\0';
	this->math = 0;
	this->lit = 0;
}

Student::Student(const char *name, int math, int lit) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	
	this->math = math;
	this->lit = lit;
}

Student::Student(const Student& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	
	this->math = other.math;
	this->lit = other.lit;
}

Student::~Student() {
	delete [] this->name;
}

/// ---------------------------------- get --------------------------------- ///
const char *Student::getName() {
	return this->name;
}

int Student::getMath() {
	return this->math;
}

int Student::getLit() {
	return this->lit;
}

/// ---------------------------------- set --------------------------------- ///
void Student::setName(const char *name) {
	delete [] this->name;
	
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Student::setMath(int const &math) {
	this->math = math;
}

void Student::setLit(int const &lit) {
	this->lit = lit;
}

/// ---------------------------------- I/O --------------------------------- ///
void Student::print() {
	cout << "Name: " << this->name << "\n";
	cout << "Math: " << this->math << "\n";
	cout << "Lit: " << this->lit << "\n";
}