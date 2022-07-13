#ifndef IO_H
#define IO_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "shape.h"

using std::cin;
using std::cout;
using std::getline;
using std::string;
using std::vector;

class IO {
	public:
		vector<string> readFile(const string &dir);
		void builder(const vector<string> &shapes, ShapeList &shapeList);
};

#endif