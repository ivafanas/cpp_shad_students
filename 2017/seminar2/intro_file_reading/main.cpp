#include <fstream>
#include <iostream>
#include <vector>


int main()
{
	// std::ifstream ifs("input.txt");
	//
	// int x = 0, y = 0;
	// ifs >> x;
	// ifs >> y;
	//
	// std::cout << x + y << std::endl;

	std::ifstream ifs("input.txt");
	// const unsigned int BUFSIZE = 64 * 1024;
	const unsigned int BUFSIZE = 2;
	std::vector<char> buffer( BUFSIZE );

	while(true)
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
