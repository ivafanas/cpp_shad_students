#include "util.h"


void solve(std::istream& is, std::ostream& os)
{
	const unsigned n = read_n(is);
	const double res = calc_exp(n);
	write_result(res, os);
}

