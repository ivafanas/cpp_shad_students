#include "polylen_calc.h"

#include <cmath>


double get_polyline_len(const std::vector<Point>& polyline)
{
	double rv = 0;
	const size_t count = polyline.size();
	for (size_t i = 0; i + 1 < count; ++i)
	{
		const double dx = polyline[i + 1].x - polyline[i].x;
		const double dy = polyline[i + 1].y - polyline[i].y;
		rv += std::sqrt(dx * dx + dy * dy);
	}
	return rv;
}
