#include "intArr.h"

using std::cout;
using std::cin;

/// ------------------------------- Cstr/Dstr ------------------------------ ///
MyIntArray::MyIntArray() {
	m_arr = nullptr;
	m_size = 0;
}

MyIntArray::MyIntArray(int size) {
	m_arr = new int[size];
	this->m_size = size;
}

MyIntArray::MyIntArray(const MyIntArray& other) {
	m_arr = new int[other.m_size];
	this->m_size = other.m_size;
	
	for (int i = 0; i < m_size; i++) {
		m_arr[i] = other.m_arr[i];
	}
}

MyIntArray::~MyIntArray() {
	delete[] m_arr;
}


/// ------------------------------- Operators ------------------------------ ///
MyIntArray& MyIntArray::operator = (const MyIntArray& other) {
	if (this != &other) {
		delete[] this->m_arr;
			
		this->m_arr = new int[other.m_size];
		this->m_size = other.m_size;
		
		for (int i = 0; i < m_size; i++) {
			this->m_arr[i] = other.m_arr[i];
		}
	}
	
	return *this;
}

// Append `other->m_arr` into `this->m_arr`
MyIntArray& MyIntArray::operator += (const MyIntArray& other) {
	int* temp = new int[m_size + other.m_size];
	
	for (int i = 0; i < m_size; i++) {
		temp[i] = m_arr[i];
	}
	
	for (int i = 0; i < other.m_size; i++) {
		temp[i + m_size] = other.m_arr[i];
	}
	
	delete[] this->m_arr;
	this->m_arr = temp;
	this->m_size += other.m_size;
	
	return *this;
}

bool MyIntArray::operator != (const MyIntArray& other) {
	if (this->m_size != other.m_size) {
		return true;
	}
	
	for (int i = 0; i < this->m_size; i++) {
		if (this->m_arr[i] != other.m_arr[i]) {
			return true;
		}
	}
	
	return false;
}

bool MyIntArray::operator < (const MyIntArray& other) {
	long long sumThis = 0;
	long long sumOther = 0;
	
	for (int i = 0; i < this->m_size; i++) {
		sumThis += this->m_arr[i];
	}
	
	for (int i = 0; i < other.m_size; i++) {
		sumOther += other.m_arr[i];
	}
	
	return (sumThis < sumOther);
}

int& MyIntArray::operator [] (int const &index) {
	return this->m_arr[index];
}

std::ostream& operator << (std::ostream& os, const MyIntArray& arr) {
	cout << "Array size: " << arr.m_size << "\n";
	
	for (int i = 0; i < arr.m_size; i++) {
		os << "[" << i << "] = " <<  arr.m_arr[i] << "\n";
	}
	
	return os;
}

std::istream& operator >> (std::istream& is, MyIntArray& arr) {
	cout << "Enter array size: ";
	is >> arr.m_size;
	
	arr = MyIntArray(arr.m_size);
	
	for (int i = 0; i < arr.m_size; i++) {
		cout << "[" << i << "] = ";
		is >> arr.m_arr[i];
	}
	
	return is;
}