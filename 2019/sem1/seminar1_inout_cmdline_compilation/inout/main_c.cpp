#include <cstdio>


int main()
{
	int sum = 0;
	for (int i = 0; i < 500'000; ++i)
	{
		int x = 0;
		std::scanf("%i", &x);
		sum += x;
	}
	std::printf("%i\n", sum);
	return 0;
}

