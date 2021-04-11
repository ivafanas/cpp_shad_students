#include "polyline.h"

#include <cmath>

float get_polyline_len(const std::vector<Point>& polyline)
{
	float rv = 0;
	for (int i = 1; i < polyline.size(); ++i)
	{
		const Point prev = polyline[i - 1];
		const Point curr = polyline[i];
        const float dx = curr.x - prev.x;
        const float dy = curr.y - prev.y;
		rv += std::sqrt(dx * dx + dy * dy);
	}
	return rv;
}

