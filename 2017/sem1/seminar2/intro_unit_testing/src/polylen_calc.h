#pragma once

#include <vector>

struct Point
{
	double x;
	double y;
};

double get_polyline_len(const std::vector<Point>& polyline);
