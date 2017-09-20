#include "util.h"

#include <cmath>
#include <iostream>

unsigned read_n()
{
	unsigned rv;
	std::cin >> rv;
	return rv;
}

void write_result(double res)
{
	std::cout << res << std::endl;
}

double calc_exp(unsigned n)
{
	const double b = 1.0 + 1.0 / n;
	return std::pow(b, n);
}
