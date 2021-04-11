#include <iostream>


int main(int argc, char** argv)
{
	int sum = 0;
	for (int i = 0; i < 200000; ++i)
	{
		int x = 0;
		std::cin >> x;
		sum += x;
	}
	std::cout << sum << std::endl;
	return 0;
}

