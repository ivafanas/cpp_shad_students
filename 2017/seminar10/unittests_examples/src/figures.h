#pragma once

#include "gtest/gtest_prod.h"

struct Point
{
	double x;
	double y;
};

class Triangle
{
public:
	Triangle(Point p, double w, double h);
	~Triangle() = default;
	void scale(double s);

private:
	Point p_;
	double w_;
	double h_;
};



class Triangle1
{
public:
	Triangle1(Point p, double w, double h);
	~Triangle1() = default;
	void scale(double s);

public:
	Point get_point_for_testing() const { return p_; }
	double get_w_for_testing() const { return w_; }
	double get_h_for_testing() const { return h_; }

private:
	Point p_;
	double w_;
	double h_;
};


class Triangle2
{
public:
	Triangle2(Point p, double w, double h);
	~Triangle2() = default;
	void scale(double s);

private:
	friend class Triangle2Test;

	Point p_;
	double w_;
	double h_;
};



class Triangle3
{
public:
	Triangle3(Point p, double w, double h);
	~Triangle3() = default;
	void scale(double s);

private:
	FRIEND_TEST(Triangle3, scale1);
	FRIEND_TEST(Triangle3, scale2);

	Point p_;
	double w_;
	double h_;
};



class Triangle4
{
public:
	Triangle4(Point p, double w, double h);
	~Triangle4() = default;
	void scale(double s);

private:
	friend class Triangle4TestingAcessor;

	Point p_;
	double w_;
	double h_;
};
