#include <iostream>

#include "src/array.h"


int main() {
	Array<int> a1(5);
	
	int *arr = a1;
	
	for (int i = 0; i < a1.getSize(); ++i) {
		std::cout << arr[i] << "\n";
	}
	
	delete[] arr;
	
	return 0;
}