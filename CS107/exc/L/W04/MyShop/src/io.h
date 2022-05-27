#pragma once

#include "ctg.h"
#include "prod.h"

Prod prod_extract(string const &line);
Ctg ctg_extract(string const &line);

void readProd(ProdVct &pvt, string const &fileName);
void readCtg(CtgVct &cvt, string const &fileName);


int main_menu();

vector<Prod> sort_vct(ProdVct const &p);
vector<Ctg> sort_vct(CtgVct const &c);

void printProd(Prod p, CtgVct cvt);
void printCtg(Ctg c);
void printSearchRes(vector<Prod> const &vtp, CtgVct const &cvt);
void print_AllCtg(ProdVct pvt, CtgVct cvt);
void print_ProdByName(ProdVct pvt, CtgVct const &cvt);
void print_ProdByPriceRange(ProdVct pvt, CtgVct const &cvt);