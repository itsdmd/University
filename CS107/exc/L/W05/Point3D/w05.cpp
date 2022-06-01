#include <iostream>

#include "src/io.h"
#include "src/point.h"
#include "src/rng.h"

using std::cout;


int main() {
	string const dir_full = "/home/dmd/Documents/University/CS107/exc/L/W05/Point3D/point3d.txt";
	string const dir = "point3d.txt";
	
	srand(time(NULL));
	int n = rng(3, 7);
	
	cout << "Please enter " << n << " 3D points (Format: \"x, y, z\"):\n";
	
	vector<Point3D> vp3;
	vp3.reserve(n);
	vp3 = extractor3D(input3D(n));
	
	cout << "\n\nFound " << vp3.size() << " point";
	(vp3.size() == 1) ? cout << ":\n" : cout << "s:\n";
	printVector3D(vp3);
	
	writeFile(dir_full, vp3);
	
	return 0;
}