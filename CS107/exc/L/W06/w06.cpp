#include <iostream>

#include "src/rng.h"
#include "src/shape.h"
#include "src/io.h"

using std::cout;
using std::string;
using std::vector;

int main() {
	vector<Shape *> shapes = generateShapes();
	
	cout << printShapes(shapes);

	// const string file_dir = "objects.txt";
	const string file_dir = "/home/dmd/Documents/University/CS107/exc/L/W06/objects.txt";
	writeToFile(file_dir, shapes);

	return 0;
}