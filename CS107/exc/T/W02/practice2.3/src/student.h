#include <string>

using std::string;


class Student {
	private:
		string name;
		float lit;
		float math;
	
	public:
		void input();
		void output();
		
		void setName(string name);
		void setLit(float lit);
		void setMath(float math);
		
		string getName();
		float getLit();
		float getMath();
		
		float calculateGPA();
		char grade();
};