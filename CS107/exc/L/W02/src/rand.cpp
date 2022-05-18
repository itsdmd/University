#pragma once

#include <random>
#include <vector>
#include "frac.cpp"


int rng(int const &min, int const &max) {
	// Ref.: https://stackoverflow.com/a/13445752
    std::random_device dev;
    std::mt19937 seed(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dis(min, max);
	
	return dis(seed);
}

void rndVct(vector<int> &vt, int const &size, int const &min, int const &max) {
	for (int i = 0; i < size; i++) {
		vt.push_back(rng(min, max));
	}
}