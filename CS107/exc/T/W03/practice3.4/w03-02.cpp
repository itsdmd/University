#include "src/array.h"


/// -------------------------------- main() -------------------------------- ///
int main() {
	Array<int> a1(0);
	
	Array<int> a2(5);
	
	Array<int [1]> a3(5);
	
	Array<int> a4(a2);
	
	Array<float> *a5 = new Array<float>;
	delete a5;
	
	
	return 0;
}