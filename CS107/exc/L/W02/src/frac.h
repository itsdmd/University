#pragma once

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