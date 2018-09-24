#include <cstdio>

int main()
{
	FILE* f = std::fopen("input.txt", "r");
	if (!f)
	{
		std::puts("cannot open file input.txt");
		return 1;
	}

	int sum = 0;
	int x = 0;
	while (fscanf(f, "%i", &x) != EOF)
		sum += x;

	std::printf("sum = %i\n", sum);

	fclose(f);

	return 0;
}
