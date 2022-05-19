#include <random>
#include "rand.h"

using std::mt19937;
using std::random_device;
using std::uniform_int_distribution;


int rng(int const &min, int const &max) {
	// Ref.: https://stackoverflow.com/a/13445752
    random_device rd;
    mt19937 seed(rd());
    uniform_int_distribution<mt19937::result_type> dis(min, max);
	
	return dis(seed);
}

void rndVct(std::vector<int> &vt, int const &size, int const &min, int const &max) {
	for (int i = 0; i < size; i++) {
		vt.push_back(rng(min, max));
	}
}