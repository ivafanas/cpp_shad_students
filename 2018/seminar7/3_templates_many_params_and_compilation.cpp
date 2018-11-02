#include <iostream>
#include <string>

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
	PlainArray<int, 10> pai;
	pai.set(5, 42);
	std::cout << pai.get(5) << std::endl;

	PlainArray<std::string, 3> pas;
	pas.set(0, "run, Forest, run!");
	std::cout << pas.get(0) << std::endl;

	pas.clear_first();
	// pai.clear_first();
	return 0;
}