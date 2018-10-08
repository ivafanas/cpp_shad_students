class A
{
public:
	A() {}
	~A() {}

	void f() {}
	virtual void g() {}
	void h() {}
};

class B : public A
{
public:
	B() {}
	virtual ~B() {}

	virtual void f() {}
	void g() {}
	void h() {}
};

class C : public B
{
public:
	C() {}
	~C() {}

	void f() {}
	void g() {}
	virtual void h() {}
};

int main()
{
	{
		C c;
		c.f(); c.g(); C.h();

		B b = c;
		b.f(); b.g(); b.h();

		A& ar = c;
		ar.f(); ar.g(); ar.h();
	}

	{
		C* cp = new C;
		A* ap = cp;
		ap->f(); ap->g(); ap->h();
		delete ap;
	}

	{
		C* cp = new C;
		B* bp = cp;
		delete bp;
	}

	return 0;
}
