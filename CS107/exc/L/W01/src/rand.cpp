#include <stdlib.h>
#include <time.h>
#include <vector>

using std::vector;


int rng(int const &min, int const &max) {
	return ((rand() % (max - min + 1)) + min);
}

void rndVct(vector<int> &vt, int const &size, int const &min, int const &max) {
	srand(time(NULL));
	
	for (int i = 0; i < size; i++) {
		vt.push_back(rng(min, max));
	}
}