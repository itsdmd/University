class Frac {
	private:
		int num;
		int den;
	
	public:
		void input();
		void output();
		
		int getNum();
		int getDenom();
		
		void setNum(int const &n);
		void setDenom(int const &d);
		
		Frac reduce();
		Frac inverse();
		Frac add(Frac const &f);
		int compare(Frac const &f);
};