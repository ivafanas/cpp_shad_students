#include "util.h"

#include <cmath>
#include <iostream>

unsigned read_n(std::istream& is)
{
	unsigned n = 0;
	is >> n;
	return n;
}

void write_result(double res, std::ostream& os)
{
	os << res << std::endl;
}

double calc_exp(unsigned n)
{
	const double b = 1 + 1.0 / n;
	return std::pow(b, n);
}

