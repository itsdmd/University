#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;


/// ---------------------------------- Ctgr --------------------------------- ///
class Ctgr {
private:
	int _id;		// Category ID
	string _name;	// Category name
public:
	Ctgr();
	Ctgr(Ctgr const &other);
	Ctgr(int const &id, string const &name);
	~Ctgr();
	
	int get_id();
	string get_name();
	
	void set_id(int const &ctgr_id);
	void set_name(string const &ctgr_name);
};

/// -------------------------------- CtgrVct -------------------------------- ///
class CtgrVct {
private:
	vector<Ctgr> _vct;
public:
	CtgrVct();
	CtgrVct(CtgrVct const &other);
	~CtgrVct();
	
	vector<Ctgr> get_vct();
	Ctgr get_ctgr(int const &ctgr_id);
	
	void set_ctgr(int const &ctgr_id, Ctgr const &c);
	
	void add_ctgr(Ctgr const &c);
};