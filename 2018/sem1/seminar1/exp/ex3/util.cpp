#include "util.h"

#include <cmath>
#include <iostream>


unsigned read_n()
{
	unsigned rv = 0;
	std::cin >> rv;
	return rv;
}

void write_result(double res)
{
	std::cout << res << std::endl;
}

double calc_exp(unsigned n)
{
	double b = 1 + 1.0 / n;
	return std::pow(b, n);
}

