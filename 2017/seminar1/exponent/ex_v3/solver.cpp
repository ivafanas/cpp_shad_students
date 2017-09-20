#include "solver.h"
#include "util.h"

void solve()
{
	const unsigned n = read_n();
	const double res = calc_exp(n);
	write_result(res);
}
