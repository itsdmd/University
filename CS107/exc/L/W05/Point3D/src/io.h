#ifndef IO_H
#define IO_H

#include <string>
#include <vector>

#include "point.h"

using std::string;
using std::vector;

bool checkRgx(string const &target, string const &rgx_pat);
vector<string> input3D(int const &n);
vector<Point3D> extractor3D(vector<string> const &inp);

void printVector3D(vector<Point3D> const &vtp3);
void writeFile(string const &file_name, vector<Point3D> const &vtp3);

#endif