#pragma once

#include "ctgr.h"
#include "prod.h"

Prod prod_extract(string const &line);
Ctgr ctgr_extract(string const &line);

void readProd(ProdVct &pvt, string const &fileName);
void readCtgr(CtgrVct &cvt, string const &fileName);


int main_menu();

vector<Prod> sort_vct(ProdVct const &p);
vector<Ctgr> sort_vct(CtgrVct const &c);

void printProd(Prod p, CtgrVct cvt);
void printCtgr(Ctgr c);
void printSearchRes(vector<Prod> const &vtp, CtgrVct const &cvt);
void print_AllCtgr(ProdVct pvt, CtgrVct cvt);
void print_ProdByName(ProdVct pvt, CtgrVct const &cvt);
void print_ProdByPriceRange(ProdVct pvt, CtgrVct const &cvt);