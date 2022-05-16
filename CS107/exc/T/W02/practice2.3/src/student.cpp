#include <iostream>
#include "student.h"

using std::cout;
using std::cin;
using std::string;


/// ---------------------------------- I/O --------------------------------- ///
void Student::input() {
	cout << "Enter student name: ";
	cin >> name;
	
	do {
		cout << "Enter student literature point: ";
		cin >> lit;
	} while (lit < 0.0);
	
	do {
		cout << "Enter student math point: ";
		cin >> math;
	} while (math < 0.0);
}

void Student::output() {
	cout << "Name: " 				<< name 			<< "\n";
	cout << "Literature point: " 	<< lit 				<< "\n";
	cout << "Math point: " 			<< math 			<< "\n";
	cout << "GPA: " 				<< calculateGPA() 	<< "\n";
	cout << "Grade: " 				<< grade() 			<< "\n";
}


/// ---------------------------------- set --------------------------------- ///
void Student::setName(string const &name) {
	this->name = name;
}

void Student::setLit(float const &lit) {
	if (lit >= 0.0) {
		this->lit = lit;
	}
	
	else {
		cout << "Literature point must be greater than or equal to 0.0\n";
	}
}

void Student::setMath(float const &math) {
	if (math >= 0.0) {
		this->math = math;
	}
	
	else {
		cout << "Math point must be greater than or equal to 0.0\n";
	}
}


/// ---------------------------------- get --------------------------------- ///
string Student::getName() {
	return name;
}

float Student::getLit() {
	return lit;
}

float Student::getMath() {
	return math;
}


/// --------------------------------- algos -------------------------------- ///
float Student::calculateGPA() {
	return ((lit + math) / 2);
}

char Student::grade() {
	if (calculateGPA() >= 9.0) {
		return 'A';
	}
	
	else if (calculateGPA() >= 7.0) {
		return 'B';
	}
	
	else if (calculateGPA() >= 5.0) {
		return 'C';
	}
	
	else {
		return 'D';
	}
}