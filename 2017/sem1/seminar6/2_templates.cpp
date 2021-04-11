#include <iostream>
#include <string>
#include <vector>

template<typename T>
void myswap(T& a, T& b)
{
	// T x = "hohoho";
	// ...;
	T tmp = a;
	// a.clear();
	a = b;
	b = tmp;
}

template<>
void myswap<std::string>(std::string& a, std::string& b)
{
	a.swap(b);
}

template<typename T, int n>
class PlainArray
{
public:
	PlainArray() = default;

	void set(size_t index, const T& x) { arr_[index]  = x; }
	const T& get(size_t index) const { return arr_[index]; }

	void clear_first()
	{
		arr_[0].clear();
	}

private:
	T arr_[n];
};

int main(int argc, char **argv)
{
	{
		std::string a, b;
		myswap(a, b);

		std::vector<int> u, v;
		myswap(u, v);

		int x = 3, y = 4;
		myswap(x, y);
	}

	{
		PlainArray<int, 10> pai;
		pai.set(5, 42);
		std::cout << pai.get(5) << std::endl;

		PlainArray<std::string, 3> pas;
		pas.set(0, "run, Forest, run!");
		std::cout << pas.get(0) << std::endl;

		pas.clear_first();
		// pai.clear_first();
	}
	return 0;
}
