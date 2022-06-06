#include <iostream>

#include "src/time.h"

using std::cin;
using std::cout;


int main() {
	Time t1(42069);
	
	Time t2(t1);
	
	Time t3(23,1,2);
	
	cout << (t1) << "\n"
		 << (t1++ < ++t2) << "\n"
		 << (t3 + 10) << "\n"
		 << t1.addSecs(2510) << "\n"
		 << t1.difInSecs(t3) << "\n"
		 << t3.setHour(5) << "\n";
	
	
	return 0;
}