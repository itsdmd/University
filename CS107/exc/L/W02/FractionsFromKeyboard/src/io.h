#pragma once

#include <string>
#include <vector>
#include "../../src/frac.h"

using std::string;
using std::vector;


bool checkRgx(string const &target, string const &rgx_pat);
Frac strToFrac(string const &s);
void singleInput(Frac &f_res, bool &valid);
void multiInput(vector<Frac> &vt_f, int const &count);