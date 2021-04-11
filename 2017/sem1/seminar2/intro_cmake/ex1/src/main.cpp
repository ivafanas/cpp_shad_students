#include "reader.h"
#include "solver.h"
#include "writer.h"


int main()
{
	const int x = read_input();
	const int res = solve(x);
	write_res(res);
	return 0;
}
