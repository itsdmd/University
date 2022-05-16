class Mnm {
	private:
		float coef;
		int expo;

	public:
		void input();
		void output();
		
		float getCoef();
		int getExpo();
		
		void setCoef(float const &);
		void setExpo(int const &);
		
		float evaluate(float const &);
		Mnm derive();
		Mnm mul(Mnm);
};