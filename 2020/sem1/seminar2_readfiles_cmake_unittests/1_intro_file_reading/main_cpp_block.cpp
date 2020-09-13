#include <fstream>
#include <iostream>
#include <vector>


int main()
{
	std::ifstream ifs("input.txt");
	if (!ifs)
	{
		std::cerr << "ERROR: cannot open file\n";
		return 1;
	}

	const unsigned BUFSIZE = 2;
	std::vector<char> buffer(BUFSIZE);

	while (true)
	{
		ifs.read(&buffer[0], buffer.size());
		const unsigned n = ifs.gcount();
		if (!n)
			break;

		std::string s(&buffer[0], n);
		std::cout << s;
	}

	return 0;
}
