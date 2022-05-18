#include <vector>

using std::vector;


int random(int const &min, int const &max) {
	return ((rand() % (max - min + 1)) + min);
}

void rndArr(vector<int> &vt, int const &size, int const &min, int const &max) {
	for (int i = 0; i < size; i++) {
		vt.push_back(random(min, max));
	}
}