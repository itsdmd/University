#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

using std::string;

class Animal {
	protected:
		string m_name;
		int m_speed;

	public:
		Animal() { this->m_name = ""; this->m_speed = 0; }
		virtual ~Animal() { this->m_name = ""; this->m_speed = 0; };
		
		virtual string getName() const { return this->m_name; }
		virtual int getSpeed() const { return this->m_speed; }
};

class Cheetah: public Animal {
	public:
		Cheetah() { this->m_name = "Cheetah"; this->m_speed = 100; };
};

class Antelope: public Animal {
	public:
		Antelope() { this->m_name = "Antelope"; this->m_speed = 80; };
};

class Lion: public Animal {
	public:
		Lion() { this->m_name = "Lion"; this->m_speed = 70; };
};

class Dog: public Animal {
	public:
		Dog() { this->m_name = "Dog"; this->m_speed = 60; };
};

class Human: public Animal {
	public:
		Human() { this->m_name = "Human"; this->m_speed = 30; };
};

class Horse: public Animal {
	public:
		Horse() { this->m_name = "Horse"; this->m_speed = 60; };
};

#endif