#include "io.h"

#include <sstream>

using std::stringstream;

vector<string> IO::readFile(const string &dir) {
	vector<string> res;

	std::ifstream inp(dir);

	if (!inp.is_open()) {
		std::cout << "Error: Cannot open " << dir << " for reading.\n";
		exit(1);
	}

	while (inp) {
		string line;

		if (getline(inp, line)) {
			res.push_back(line);
		}
	}

	inp.close();

	return res;
}

// Rectangle: Width=3.12, Height=3.5
// Circle: Radius=3
// Triangle: A=3, B=4, C=5
void IO::builder(const vector<string> &shapes, ShapeList &shapeList) {
	const vector<string> keywords = {"Rectangle:", "Width=", "Height=",
									 "Circle:", "Radius=",
									 "Triangle:", "A=", "B=", "C="};

	for (auto &shape : shapes) {
		stringstream ss(shape);
		string type;
		ss >> type;

		if (type == keywords[0]) {
			string width, height;
			ss >> width >> height;

			width = width.substr((keywords[1].length()), (width.length() - keywords[1].length() - 1));				 // 1 is for the ','
			height = height.substr((keywords[2].length()), (height.length() - keywords[2].length()));

			shapeList.add(new Rectangle(stof(width), stof(height)));
		} else if (type == keywords[3]) {
			string radius;
			ss >> radius;

			radius = radius.substr(keywords[4].length(), (radius.length() - keywords[4].length()));

			shapeList.add(new Circle(stof(radius)));
		} else if (type == keywords[5]) {
			string a, b, c;
			ss >> a >> b >> c;

			a = a.substr((keywords[6].length()), (a.length() - keywords[6].length() - 1));
			b = b.substr((keywords[7].length()), (b.length() - keywords[7].length() - 1));
			c = c.substr((keywords[8].length()), (c.length() - keywords[8].length()));

			shapeList.add(new Triangle(stof(a), stof(b), stof(c)));
		} else {
			std::cout << "Error: Unknown shape type: " << type << "\n";
			continue;
		}
	}
}