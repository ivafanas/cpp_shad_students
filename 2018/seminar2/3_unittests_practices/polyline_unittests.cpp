#include "gtest/gtest.h"

#include "polyline.h"


TEST(get_polyline_len, empty_polyline)
{
	std::vector<Point> empty_poly;
	const double len = get_polyline_len(empty_poly);
	EXPECT_EQ(0, len);
}

TEST(get_polyline_len, single_point_polyline)
{
	std::vector<Point> empty_poly{{1,1}};
	const double len = get_polyline_len(empty_poly);
	EXPECT_EQ(0, len);
}

TEST(get_polyline_len, single_point_polyline)
{
	std::vector<Point> empty_poly{{1,1}};
	const double len = get_polyline_len(empty_poly);
	EXPECT_EQ(0, len);
}

TEST(get_polyline_len, single_segment_polyline)
{
	std::vector<Point> empty_poly{{1,1}, {1, 2}};
	const double len = get_polyline_len(empty_poly);
	EXPECT_EQ(1, len);
}

TEST(get_polyline_len, std_polyline)
{
	std::vector<Point> empty_poly{{1,1}, {1, 2}};
	const double len = get_polyline_len(empty_poly);
	EXPECT_EQ(1, len);
}
