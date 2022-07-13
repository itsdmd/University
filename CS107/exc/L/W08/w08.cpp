#include <iostream>

#include "src/io.h"
#include "src/shape.h"

using std::cin;
using std::cout;

int main() {
	const string file_dir = "/home/dmd/Documents/University/CS107/exc/L/W08/data.txt";
	// const string file_dir = "data.txt";

	IO io;
	ShapeList sl;

	io.builder(io.readFile(file_dir), sl);

	sl.print();

	return 0;
}