class A
{
public:
	A() {}
	~A() {}

	void f() { std::cout << "f();"; }
	void f() const { std::cout << "f() const;" }
};


int main()
{
	A a;
	a.f();

	const A ca;
	ca.f();

	const A& car = a;
	car.f();

	A& ar = a;
	ar.f();

	A* const acp = &a;
	acp->f();

	const A* cap = &a;
	cap->f();

	const A a2 = a;
	a2.f();

	return 0;
}
