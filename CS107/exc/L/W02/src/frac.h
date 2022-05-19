#pragma once

#include <vector>

using std::vector;

class Frac {
  private:
    int num;    // numerator
    int den;    // denominator
    
  public:
    int getNum();
    int getDen();
    
    void setNum(int const &n);
    void setDen(int const &d);
    
		Frac reduce();
};


void fracVctGen(vector<int> const &vt1, vector<int> const &vt2, vector<Frac> &vt_f);
void printFVct(vector<Frac> const &vt);
void printFVctReduced(vector<Frac> const &vt);
void printFVctDec(vector<Frac> const &vt);
void printFVctPct(vector<Frac> const &vt);