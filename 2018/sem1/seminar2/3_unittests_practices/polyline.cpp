#include "polyline.h"

#include <cmath>

float get_polyline_len(const std::vector<Point>& polyline)
{
	double rv = 0;
	for (int i = 1; i < polyline.size(); ++i)
	{
		const Point& prev = polyline[i-1];
		const Point& curr = polyline[i];
		rv += std::sqrt(
			(curr.x - prev.x) * (curr.x - prev.x) +
			(curr.y - prev.y) * (curr.y - prev.y));
	}
	return rv;
}

