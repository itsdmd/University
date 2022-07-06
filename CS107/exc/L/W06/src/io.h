#include <string>
#include <vector>
#include "shape.h"

using std::string;
using std::vector;

string printShapes(const vector<Shape *> &shapes);
void writeToFile(const string &file_name, const vector<Shape *> &shapes);
vector<Shape *> generateShapes();