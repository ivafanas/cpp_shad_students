#include "gtest/gtest.h"

#include "figures.h"


TEST(Triangle1, scale)
{
	Triangle1 t(Point{0, 0}, 3, 3);
	t.scale(2);
	EXPECT_EQ(6, t.get_w_for_testing());
}


class Triangle2Test : public testing::Test
{
public:
	Triangle2Test()
		: t_(Point{0, 0}, 3, 3)
	{}
	~Triangle2Test() override = default;

protected:
	Point get_point() const { return t_.p_; }
	double get_w() const { return t_.w_; }
	double get_h() const { return t_.h_; }

	Triangle2 t_;
};

TEST_F(Triangle2Test, scale)
{
    t_.scale(2);
	EXPECT_EQ(6, get_w());
}



TEST(Triangle3, scale1)
{
	Triangle3 t(Point{0, 0}, 3, 3);
	t.scale(1);
	EXPECT_EQ(3, t.w_);
}

TEST(Triangle3, scale2)
{
	Triangle3 t(Point{0, 0}, 3, 3);
	t.scale(2);
	EXPECT_EQ(6, t.w_);
}



class Triangle4TestingAcessor
{
public:
	static Point& point(Triangle4& t) { return t.p_; }
	static double& width(Triangle4& t) { return t.w_; }
	static double& height(Triangle4& t) { return t.h_; }
};

TEST(Triangle4, scale1)
{
	Triangle4 t(Point{0, 0}, 3, 3);
	t.scale(1);
	EXPECT_EQ(3, Triangle4TestingAcessor::width(t));
}

TEST(Triangle4, scale2)
{
	Triangle4 t(Point{0, 0}, 3, 3);
	t.scale(2);
	EXPECT_EQ(6, Triangle4TestingAcessor::width(t));
}
