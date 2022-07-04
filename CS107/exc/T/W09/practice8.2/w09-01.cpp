#include "src/shape.h"

#include <iostream>


using std::cout;

int main() {
	Rectangle r1(1, 2, 3, 4);
	Triangle t1(1, 2, 3, 4, 5, 6);
	Circle c1(1, 2, 3);
	
	vector<Shape*> shapes;
	
	shapes.push_back(&r1);
	shapes.push_back(&t1);
	shapes.push_back(&c1);
	
	printShapeInfos(shapes);
	
	for (int i = 0; i < shapes.size(); i++) {
		shapes[i] = nullptr;
	}
	
	return 0;
}