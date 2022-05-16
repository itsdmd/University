class Mnm {
	private:
		float coef;
		int expo;

	public:
		void input();
		void output();
		
		float getCoef();
		int getExpo();
		
		void setCoef(float const &c);
		void setExpo(int const &e);
		
		float evaluate(float const &x);
		Mnm derive();
		Mnm mul(Mnm m);
};