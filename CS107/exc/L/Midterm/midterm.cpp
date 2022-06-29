#include <iostream>

#include "src/intArr.h"

using std::cin;
using std::cout;


int main() {
	MyIntArray arr1;
	cin >> arr1;
	
	MyIntArray arr2(arr1);
	
	arr1[2] = 9;
	arr2 += arr1;
	cout << arr2;
	
	if (arr1 < arr2)
		cout << "arr1 less than arr2\n";
	
	return 0;
}