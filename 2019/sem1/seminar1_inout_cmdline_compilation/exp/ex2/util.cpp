#include "util.h"

#include <cmath>
#include <iostream>


unsigned read_n(std::istream& is)
{
	unsigned rv = 0;
	is >> rv;
	return rv;
}

void write_result(double res, std::ostream& os)
{
	os << res << std::endl;
}

double calc_exp(unsigned n)
{
	double b = 1 + 1.0 / n;
	return std::pow(b, n);
}

