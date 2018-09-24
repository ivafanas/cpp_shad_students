#pragma once

#include <vector>

struct Point
{
	float x;
	float y;
};

float get_polyline_len(const std::vector<Point>& polyline);

