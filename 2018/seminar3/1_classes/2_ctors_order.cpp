#include <iostream>


class M1
{
public:
	M1() { std::cout << "M1 "; }
	~M1() { std::cout << "~M1 "; }
};

class M2
{
public:
	M2() { std::cout << "M2 "; }
	~M2() { std::cout << "~M2 "; }
};

class M3
{
public:
	M3() { std::cout << "M3 "; }
	~M3() { std::cout << "~M3 "; }
};

class A
{
public:
	A() { std::cout << "A "; }
	~A() { std::cout << "~A "; }

private:
	M1 m1_;
	M2 m2_;
};

class B : public A
{
public:
	B() { std::cout << "B "; }
	~B() { std::cout << "~B "; }

private:
	M3 m3_;
};


// show this later
// A a;

int main()
{
	std::cout << "hello!" << std::endl;
	B b;
	std::cout << std::endl << "goodbye!" << std::endl;
	return 0;
}
