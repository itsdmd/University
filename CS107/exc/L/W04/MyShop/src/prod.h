#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


/// --------------------------------- Prod --------------------------------- ///
class Prod {
private:
	int _id;
	string _name;
	long _price;
	int _ctgr;			// Category ID
public:
	Prod();
	Prod(Prod const &other);
	Prod(int const &id, string const &name, long const &price, int const &ctgr);
	~Prod();
	
	int get_id();
	string get_name();
	long get_price();
	int get_ctgr();
	
	void set_id(int const &id);
	void set_name(string const &name);
	void set_price(long const &price);
	void set_ctgr(int const &ctgr);
};

/// -------------------------------- ProdVct ------------------------------- ///
class ProdVct {
private:
	vector<Prod> _vct;
public:
	ProdVct();
	ProdVct(ProdVct const &other);
	~ProdVct();
	
	vector<Prod> get_vct();
	vector<Prod> get_vct(string keyword);
	vector<Prod> get_vct(long const &min_price, long const &max_price);
	
	Prod get_prod(int const &p_id);
	Prod get_prod(string const &p_name);
	
	void set_prod(int const &p_id, Prod const &p);
	void set_prod(string const &p_name, Prod const &p);
	
	void add_prod(Prod const &p);
};