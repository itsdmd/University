#include "src/shape.h"

#include <iostream>


using std::cout;

int main() {
	Rectangle r1(1, 2, 3, 4);
	Triangle t1(1, 2, 3, 4, 5, 6);
	Circle c1(1, 2, 3);
	
	vector<Shape*> rec;
	vector<Shape*> tri;
	vector<Shape*> cir;
	
	rec.push_back(&r1);
	tri.push_back(&t1);
	cir.push_back(&c1);
	
	printShapeInfos(rec, tri, cir);
	
	for (int i = 0; i < rec.size(); i++) {
		rec[i] = nullptr;
	}
	
	for (int i = 0; i < tri.size(); i++) {
		tri[i] = nullptr;
	}
	
	for (int i = 0; i < cir.size(); i++) {
		cir[i] = nullptr;
	}
	
	return 0;
}