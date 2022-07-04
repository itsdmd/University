#include <iostream>

#include "src/animal.cpp"

using std::cout;

void compareSpeed(Animal* a, Animal* b) {
	if (a->getSpeed() > b->getSpeed()) {
		cout << a->getName() << " will win against " << b->getName() << "\n";
	}

	else if (a->getSpeed() == b->getSpeed()) {
		if (a->getName() == b->getName()) {
			cout << "You are comparing two same animals!\n";
		} else {
			cout << "Both " << a->getName() << " and " << b->getName() << " have the same speed, thus a tie.\n";
		}
	}

	else {
		cout << b->getName() << " will win against " << a->getName() << "\n";
	}
}

int main() {
	Animal* a = new Lion();
	Animal* b = new Horse();
	Animal* c = new Cheetah();
	Animal* d = new Dog();
	Animal* f = new Antelope();
	Animal* e = new Human();

	compareSpeed(a, b);
	compareSpeed(a, c);
	compareSpeed(a, d);
	compareSpeed(a, e);
	compareSpeed(a, f);

	compareSpeed(b, c);
	compareSpeed(b, d);
	compareSpeed(b, e);
	compareSpeed(b, f);

	compareSpeed(c, d);
	compareSpeed(c, e);
	compareSpeed(c, f);

	compareSpeed(d, e);
	compareSpeed(d, f);

	compareSpeed(e, f);

	compareSpeed(f, f);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;

	return 0;
}