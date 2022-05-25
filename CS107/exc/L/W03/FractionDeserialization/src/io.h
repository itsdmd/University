#pragma once

#include <string>
#include <vector>
#include "frac.h"

using std::string;
using std::vector;


bool checkRgx(string const &target, string const &rgx_pat);
Frac strToFrac(string const &s);
void fracInp(string const &inp, Frac &f_inp, bool &valid);
void multiFracInp(FracVct &fvt, int const &count);

int loadData(string const &dir, FracVct &fvt);