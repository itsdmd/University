#pragma once

#include "array.h"


/// ------------------------------- Cstr/Dstr ------------------------------ ///
template <class T>
Array<T>::Array() {
	this->size = 0;
	this->data = nullptr;
}

template <class T>
Array<T>::Array(int const &size) {
	this->data = new T[size];
	this->size = size;
}

template <class T>
Array<T>::Array(Array const &other) {
	this->data = new T[other.size];
	this->size = other.size;
	
	for (int i = 0; i < this->size; i++) {
		this->data[i] = other.data[i];
	}
}

template <class T>
Array<T>::~Array() {
	delete[] this->data;
}

template <class T>
T &Array<T>::getVal(int const &index) {
	return this->data[index];
}

template <class T>
int Array<T>::getSize() {
	return this->size;
}

template <class T>
void Array<T>::setSize(int const &size) {
	int oldSize = this->size;
	T *oldData = this->data;
	
	this->data = new T[size];
	this->size = size;
	
	for (int i = 0; i < size; i++) {
		if (i < oldSize) {
			this->data[i] = oldData[i];
		}
		
		else {
			this->data[i] = T();
		}
	}
	
	delete[] oldData;
}