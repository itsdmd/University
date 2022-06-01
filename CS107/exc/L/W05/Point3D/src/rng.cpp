#include <stdlib.h>
#include <time.h>

#include "rng.h"


int rng(int const &min, int const &max) {
	return ((rand() % (max - min + 1)) + min);
}

std::vector<int> rndVct(int const &size, int const &min, int const &max) {
	std::vector<int> res;
	
	srand(time(NULL));
	
	for (int i = 0; i < size; i++) {
	res.push_back(rng(min, max));
	}
	
	
	return res;
}