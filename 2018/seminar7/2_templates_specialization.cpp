#include <string>
#include <vector>

template<typename T>
void myswap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<>
void myswap<std::string>(std::string& a, std::string& b)
{
	a.swap(b);
}

int main(int argc, char **argv)
{
	std::string a, b;
	myswap(a, b);

	std::vector<int> u, v;
	myswap(u, v);

	int x = 3, y = 4;
	myswap(x, y);

	return 0;
}