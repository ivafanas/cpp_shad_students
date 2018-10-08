#include <iostream>


class Name
{
public:
	Name() { std::cout << "Name "; }
	~Name() { std::cout << "~Name "; }
};

class Brain
{
public:
	Brain() { std::cout << "Brain "; }
	~Brain() { std::cout << "~Brain "; }
};

class Leg
{
public:
	Leg() { std::cout << "Leg "; }
	~Leg() { std::cout << "~Leg "; }
};

class Tail
{
public:
	Tail() { std::cout << "Tail "; }
	~Tail() { std::cout << "~Tail "; }
};

class Animal
{
public:
	Animal() { std::cout << "Animal "; }
	~Animal() { std::cout << "~Animal "; }

private:
	Brain brain_;
	Name name_;
};

class Cat : public Animal
{
public:
	Cat() { std::cout << "Cat "; }
	~Cat() { std::cout << "~Cat "; }

private:
	Leg l1_;
	Leg l2_;
	Leg l3_;
	Leg l4_;
	Tail tail_;
};


// show this later
// Animal animal;

int main()
{
	std::cout << "hello!" << std::endl;
	Cat cat;
	std::cout << std::endl << "goodbye!" << std::endl;
	return 0;
}
