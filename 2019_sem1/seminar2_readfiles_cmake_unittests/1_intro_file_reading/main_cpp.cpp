#include <fstream>
#include <iostream>


int main()
{
	std::ifstream ifs("input.txt");
	if (!ifs)
	{
		std::cerr << "ERROR: cannot open file input.txt" << std::endl;
		return 1;
	}

	int sum = 0, x = 0;
	while (ifs >> x)
		sum += x;

	std::cout << sum << std::endl;

	return 0;
}

