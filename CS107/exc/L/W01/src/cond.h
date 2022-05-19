#pragma once

#include <vector>

bool all(int const &val);

bool even(int const &val);

bool odd(int const &val);

bool palindromic(int const &val);

bool square(int const &val);

int countCond(int const *arr, int const &size, bool (*cond)(int const &));

int countCond(std::vector<int> const &vt, bool (*cond)(int const &));