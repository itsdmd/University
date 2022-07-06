#include "io.h"

#include <fstream>

#include "rng.h"

string printShapes(const vector<Shape *> &shapes) {
	string result = "";

	for (auto shape : shapes) {
		result += shape->print(true) + "\n";
	}

	return result;
}

void writeToFile(const string &file_name, const vector<Shape *> &shapes) {
	std::ofstream ofs(file_name);

	for (int i = 0; i < shapes.size(); i++) {
		ofs << shapes[i]->print(false);
	}

	ofs.close();
}

vector<Shape *> generateShapes() {
	const int num_of_shapes = rndVct(1, 6, 12)[0];

	vector<int> shape_type = rndVct(num_of_shapes, 0, 2);

	vector<Shape *> shapes;

	for (int i = 0; i < num_of_shapes; i++) {
		vector<int> rnd_dim = rndVct(2, 1, 10);

		switch (shape_type[i]) {
			case 0: {
				shapes.push_back(new Rectangle(rnd_dim[0], rnd_dim[1]));
				break;
			}

			case 1: {
				shapes.push_back(new Triangle(rnd_dim[0], rnd_dim[1], rnd_dim[2]));
				break;
			}

			case 2: {
				shapes.push_back(new Circle(rnd_dim[0]));
				break;
			}

			default:
				break;
		}
	}


	return shapes;
}