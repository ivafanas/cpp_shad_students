#include "polylen_calc.h"

#include <vector>
#include <iostream>


int main()
{
	const std::vector<Point> polyline{
		{0., 0.},
		{3., 4.},
		{3., 0.}
	};

	const double res = get_polyline_len(polyline);

	std::cout << res << std::endl;

	return 0;
}
