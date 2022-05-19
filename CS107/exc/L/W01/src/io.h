#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


void inp_int(int &target, bool &success);

void singleInput(string const &msg, int &val, int const &min, int const &max);

void multiInput(int *arr, int const &count, int const &min, int const &max);

void printArr(int const *arr, int const &size, bool (*cond)(int const &));

void printVct(vector<int> const &vt, bool (*cond)(int const &));

void printCond(string const &msg, int const *arr, int const &size, bool (*cond)(int const &));

void printCond(string const &msg, vector<int> const &vt, bool (*cond)(int const &));