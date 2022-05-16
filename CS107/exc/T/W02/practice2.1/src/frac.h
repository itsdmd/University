class Frac {
	private:
		int num;
		int den;
	
	public:
		void input();
		void output();
		
		int getNum();
		int getDenom();
		
		void setNum(int const &);
		void setDenom(int const &);
		
		Frac reduce();
		Frac inverse();
		Frac add(Frac const &);
		int compare(Frac const &);
};