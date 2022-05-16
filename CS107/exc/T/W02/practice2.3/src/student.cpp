#include <iostream>
#include "student.h"

using std::cout;
using std::cin;
using std::string;


/// ---------------------------------- I/O --------------------------------- ///
void InputHandler(float &target) {
	do {
		cin >> target;
	} while (target < 0.0);
}

void Student::input() {
	cout << "Enter student name: ";
	cin >> name;
	
	cout << "Enter student literature point: ";
	InputHandler(lit);
	
	cout << "Enter student math point: ";
	InputHandler(math);
}

void Student::output() {
	cout << "Name: " 				<< name 			<< "\n";
	cout << "Literature point: " 	<< lit 				<< "\n";
	cout << "Math point: " 			<< math 			<< "\n";
	cout << "GPA: " 				<< calculateGPA() 	<< "\n";
	cout << "Grade: " 				<< grade() 			<< "\n";
}


/// ---------------------------------- set --------------------------------- ///
void Student::setName(string name) {
	this->name = name;
}

void Student::setLit(float lit) {
	this->lit = lit;
}

void Student::setMath(float math) {
	this->math = math;
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