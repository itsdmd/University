#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

#include "rng.h"

// https://stackoverflow.com/a/23143753/16784616
std::vector<int> rndVct(const int &size, const int &left, const int &right) {
	std::vector<int> res (size);

	std::random_device device;
	std::mt19937 engine {device()};
	std::uniform_int_distribution<int> dist {left, right};

	auto gen = [&dist, &engine]() {
		return dist(engine);
	};

	generate(begin(res), end(res), gen);


	return res;
}