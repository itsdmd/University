#pragma once

#include <regex>
#include <string>
#include <tuple>
#include <vector>

using std::regex;
using std::string;
using std::tuple;
using std::vector;

class Frac {
  private:
    int num;        // numerator
    int den;        // denominator
    
  public:
    enum ParseErrorCode {
      EmptyInput,
      InvalidInputFormat,
      ZeroDenominator
    };
    
    static tuple<bool, Frac, int, string> parse(string buffer, Frac f) {
      bool success = true;
      int errorCode = 0;
      string message = "";

      if (buffer.length() == 0) {
        success = false;
        errorCode = Frac::ParseErrorCode::EmptyInput;
        message = "Input cannot be empty";
      }

      if (!std::regex_match(buffer, regex("\\d+\\/\\d+"))) {
        success = false;
        errorCode = Frac::ParseErrorCode::InvalidInputFormat;
        message = "Invalid input format";
      }

      if (f.getDen() == 0) {
        success = false;
        errorCode = Frac::ParseErrorCode::ZeroDenominator;
        message = "Cannot divide by zero";
      }

      auto result = make_tuple(success, f, errorCode, message);
      return result;
    };
    
    int getNum();
    int getDen();
    
    void setNum(int const &n);
    void setDen(int const &d);
    
		Frac reduce();
};


void fracVctGen(vector<int> const &vt1, vector<int> const &vt2, vector<Frac> &vt_f);
void fracVctSum(vector<Frac> const &vt_inp, Frac &f_res);
void printFrac(Frac f);
void printFracMixed(Frac f);
void printFVct(vector<Frac> const &vt);
void printFVctReduced(vector<Frac> const &vt);
void printFVctDec(vector<Frac> const &vt);
void printFVctPct(vector<Frac> const &vt);