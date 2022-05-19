#pragma once

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
		
		void setName(string const &name);
		void setLit(float const &lit);
		void setMath(float const &math);
		
		string getName();
		float getLit();
		float getMath();
		
		float calculateGPA();
		char grade();
};