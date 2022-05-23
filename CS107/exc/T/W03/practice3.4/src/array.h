#pragma once

template <class T>
class Array {
private:
	T *data;
	int size;
	
public:
	Array();
	Array(int const &size);
	Array(Array const &other);
	~Array();
	
	T &getVal(int const &index);
	int getSize();
	
	void setSize(int const &size);
};

#include "array.cpp"