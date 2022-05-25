#include <iostream>
#include <fstream>
#include <string>

#include "src/point.h"
#include "src/rand.h"

using std::cin;
using std::cout;
using std::string;



void saveData(string const &filename, PointVct pv) {
	std::ofstream ofs(filename);
	
	for (int i = 0; i < pv.getSize(); i++) {
		ofs << "(" << pv.getData(i).getX() << ", " << pv.getData(i).getY() << ")" << std::endl;
	}
	
	ofs.close();
}


/// -------------------------------- main() -------------------------------- ///
int main() {
	string const dir_full = "/home/dmd/Documents/University/CS107/exc/L/W03/PointSerialization/points.txt";
	string const dir = "points.txt";
	
	int min = 1,
		max = 100;
	int size;
	PointVct pvt;
	vector<int> vt1, vt2;
	
	/// ------------------------------ Generating ------------------------------ ///
	srand(time(NULL));
	size = rng(5, 10);
	
	rndVct(vt1, size, min, max);
	rndVct(vt2, size, min, max);

	pvt = PointVct(vt1, vt2);

	/// -------------------------------- Output -------------------------------- ///
	saveData(dir_full, pvt);
	
	
	return 0;
}