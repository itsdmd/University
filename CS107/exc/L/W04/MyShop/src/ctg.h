#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


/// ---------------------------------- Ctg --------------------------------- ///
class Ctg {
private:
	int _id;		// Category ID
	string _name;	// Category name
public:
	Ctg();
	Ctg(Ctg const &other);
	Ctg(int const &id, string const &name);
	~Ctg();
	
	int get_id();
	string get_name();
	
	void set_id(int const &ctg_id);
	void set_name(string const &ctg_name);
};

/// -------------------------------- CtgVct -------------------------------- ///
class CtgVct {
private:
	vector<Ctg> _vct;
public:
	CtgVct();
	CtgVct(CtgVct const &other);
	~CtgVct();
	
	vector<Ctg> get_vct();
	Ctg get_ctg(int const &ctg_id);
	
	void set_ctg(int const &ctg_id, Ctg const &c);
	
	void add_ctg(Ctg const &c);
};