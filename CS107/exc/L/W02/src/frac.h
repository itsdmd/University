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
  Frac();
  Frac(int n, int d);
  
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
  
  void printFrac();
  void printFracMixed();
  
  Frac reduce();
};

class FracVct {
private:
  vector<Frac> vt;

public:
  FracVct();
  FracVct(FracVct const &other);
  FracVct(vector<int> const &fv1, vector<int> const &fv2);
  ~FracVct();
  
  vector<Frac> getVct();
  Frac getElement(int const &i);
  
  void setElement(int const &i, Frac const &f);
  void addElement(Frac const &f);
  
  void printFVct();
  void printFVctReduced();
  void printFVctDec();
  void printFVctPct();
  
  Frac fracVctSum();
};