#include "gtest/gtest.h"

#include "polylen_calc.h"


TEST(GetPolylineLen, GenericPolyline)
{
	// arrange
	std::vector<Point> polyline{
		{0., 0.},
		{3., 4.},
		{3., 0.}
	};

	// act
	double res = get_polyline_len(polyline);

	// assert
	EXPECT_DOUBLE_EQ(9., res);
}

TEST(GetPolylineLen, EmptyPolyline)
{
	std::vector<Point> polyline;

	double res = get_polyline_len(polyline);

	EXPECT_DOUBLE_EQ(0., res);
}

TEST(GetPolylineLen, SinglePoint)
{
	std::vector<Point> polyline{
		{1., 1.}
	};

	double res = get_polyline_len(polyline);

	EXPECT_DOUBLE_EQ(0., res);
}

TEST(GetPolylineLen, RepeatingPoint)
{
	std::vector<Point> polyline{
		{0., 0.},
		{3., 4.},
		{3., 4.}
	};

	double res = get_polyline_len(polyline);

	EXPECT_DOUBLE_EQ(5., res);
}
