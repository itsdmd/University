#pragma once

#include <iostream>

template <typename T>
class Array {
private:
	T *m_data;
	int m_size;
	
public:
	Array<T>();
	Array<T>(int const &size);
	Array<T>(const Array &other);
	~Array<T>();
	
	Array<T>& operator = (const Array& other);
	bool operator != (const Array& other);
	T& operator [] (int const &index);
	operator T*() {
		T *convrt = new T[m_size];
		
		for (int i = 0; i < m_size; ++i) {
			convrt[i] = m_data[i];
		}
		
		return convrt;
	};
	template <typename U> friend std::ostream& operator << (std::ostream& os, const Array<U>& m);
	template <typename U> friend std::istream& operator >> (std::istream& is, Array<U>& m);
	
	T get(int const &index);
	int getSize();
	
	void set(int const &index, T const &value);
	void setSize(int const &size);
};


/// ------------------------------- Cstr/Dstr ------------------------------ ///
/* #region   */
template <typename T>
Array<T>::Array() {
	this->m_data = nullptr;
	this->m_size = 0;
}

template <typename T>
Array<T>::Array(int const &size) {
	this->m_data = new T[size];
	this->m_size = size;
}

template <typename T>
Array<T>::Array(const Array &other) {
	this->m_data = new T[other.m_size];
	for (int i = 0; i < other.m_size; i++) {
		this->m_data[i] = other.m_data[i];
	}
	this->m_size = other.m_size;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->m_data;
}
/* #endregion */


/// ------------------------------- Operators ------------------------------ ///
/* #region   */
/* #region   */
template <typename T>
Array<T>& Array<T>::operator = (const Array& other) {
	this->setSize(other.m_size);
	
	return *this;
}

template <typename T>
T& Array<T>::operator [] (int const &index) {
	return this->m_data[index];
}
/* #endregion */


/* #region   */
template <typename U>
std::ostream& operator << (std::ostream& os, const Array<U>& m) {
	for (int i = 0; i < m.m_size; i++) {
		os << "[" << i << "] " << m.m_data[i] << "\n";
	}
	
	return os;
}

template <typename U>
std::istream& operator >> (std::istream& is, Array<U>& m) {
	for (int i = 0; i < m.m_size; i++) {
		is >> m.m_data[i];
	}
	
	return is;
}
/* #endregion */
/* #endregion */


/// -------------------------------- get/set ------------------------------- ///
template <typename T>
T Array<T>::get(int const &index) {
	return this->m_data[index];
}

template <typename T>
int Array<T>::getSize() {
	return this->m_size;
}

template <typename T>
void Array<T>::set(int const &index, T const &value) {
	this->m_data[index] = value;
}

template <typename T>
void Array<T>::setSize(int const &size) {
	int old_size = this->m_size;
	
	T *old_data = new T[old_size];
	for (int i = 0; i < old_size; i++) {
		old_data[i] = this->m_data[i];
	}
	
	if (this->m_size != size) {
		delete[] this->m_data;
		
		this->m_data = new T[size];
		this->m_size = size;
	}
	
	for (int i = 0; i < size; i++) {
		this->m_data[i] = old_data[i];
		
		if (i >= old_size) {
			this->m_data[i] = 0;
		}
	}
	
	delete[] old_data;
}