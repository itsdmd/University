#pragma once

class Array {
	private:
		int *arr;
		int size;
		
		template <typename T>
		bool increment(T const &a, T const &b);
		template <typename T>
		bool decrement(T const &a, T const &b);

	public:
		template <typename T>
		void input();
		void output();

		int getSize();
		template <typename T>
		T getElement(int const &index);

		void setSize(int const &size);
		template <typename T>
		void setElement(int const &index, T const &element);

		template <typename T>
		int find(T element);
		template <typename T>
		void sort(bool (*compare)(T, T));
};