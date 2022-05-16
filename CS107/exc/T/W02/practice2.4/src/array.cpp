#include <iostream>
#include "array.h"
#include "swap.cpp"

using std::cout;
using std::cin;


/// ---------------------------------- I/O --------------------------------- ///
template <typename T>
void Array::input() {
	cout << "Enter array size: ";
	cin >> size;
	
	arr = new T[size];
	
	cout << "Enter array elements: ";
	for (int i = 0; i < size; i++) {
		cout << "[" << i << "] ";
		cin >> arr[i];
	}
}

void Array::output() {
	for (int i = 0; i < size; i++) {
		cout << "\n" << "[" << i << "] = " << arr[i];
	}
	
	cout << "\n";
}


/// ---------------------------------- get --------------------------------- ///
int Array::getSize() {
	return size;
}

template <typename T>
T Array::getElement(int const &index) {
	return arr[index];
}


/// ---------------------------------- set --------------------------------- ///
void Array::setSize(int const &size) {
	this->size = size;
}

template <typename T>
void Array::setElement(int const &index, T const &element) {
	arr[index] = element;
}


/// --------------------------------- algos -------------------------------- ///
template <typename T>
int Array::find(T element) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == element) {
			return i;
		}
	}
	
	return -1;
}

template <typename T>
bool Array::increment(T const &a, T const &b) {
	return (a < b);
}

template <typename T>
bool Array::decrement(T const &a, T const &b) {
	return (a > b);
}

template <typename T>
void Array::sort(bool (*compare)(T, T)) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (size - 1); j++) {
			if (!compare(arr[j], arr[j + 1])) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}