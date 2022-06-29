#ifndef INTARR_H
#define INTARR_H

#include <iostream>

class MyIntArray {
private:
	int* m_arr;
	int m_size;

public:
	MyIntArray();
	MyIntArray(int size);
	MyIntArray(const MyIntArray& other);
	~MyIntArray();

	MyIntArray& operator =  (const MyIntArray& other);
	MyIntArray& operator += (const MyIntArray& other);
	bool operator != (const MyIntArray& other);
	bool operator <  (const MyIntArray& other);
	int& operator [] (int const &index);
	friend std::ostream& operator << (std::ostream& os, const MyIntArray& arr);
	friend std::istream& operator >> (std::istream& is, MyIntArray& arr);
};

#endif