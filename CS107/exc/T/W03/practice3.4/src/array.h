#pragma once

template <class T>
class Array {
private:
	T *data;
	int size;
	
public:
	Array() {
		this->size = 0;
		this->data = nullptr;
	};
	
	Array(int const &size) {
		this->data = new T[size];
		this->size = size;
	};
	
	Array(Array const &other) {
		this->data = new T[other.size];
		this->size = other.size;
		
		for (int i = 0; i < this->size; i++) {
			this->data[i] = other.data[i];
		}
	};
	
	~Array() {
		delete[] this->data;
	};
	
	
	Array<T>& operator = (const Array& other) {
		if (&other == this) {
			return *this;
		}
		
		this->setSize(other.m_size);
		
		this->m_data = new T[other.m_size];
		for (int i = 0; i < other.m_size; i++) {
			this->m_data[i] = other.m_data[i];
		}
		
		return *this;
	}
	
	
	T &getVal(int const &index) {
		return this->data[index];
	};
	
	int getSize() {
		return this->size;
	};
	
	
	void setSize(int const &size) {
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
	};
};