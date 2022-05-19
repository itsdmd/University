#pragma once

class Frac {
	private:
		int num;
		int den;
	
	public:
		void input();
		void output();
		
		int getNum();
		int getDen();
		
		void setNum(int const &n);
		void setDen(int const &d);
		
		Frac reduce();
		Frac inverse();
		Frac add(Frac const &f);
		int compare(Frac const &f);
};