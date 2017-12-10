#include "figures.h"

Triangle::Triangle(Point p, double w, double h)
	: p_(p)
	, w_(w)
	, h_(h)
{
}

void Triangle::scale(double s)
{
	p_.x += (1 - s) * w_ / 3;
	p_.y += (1 - s) * h_ / 3;
	w_ *= s;
	h_ *= s;
}


Triangle1::Triangle1(Point p, double w, double h)
	: p_(p)
	, w_(w)
	, h_(h)
{
}

void Triangle1::scale(double s)
{
	p_.x += (1 - s) * w_ / 3;
	p_.y += (1 - s) * h_ / 3;
	w_ *= s;
	h_ *= s;
}


Triangle2::Triangle2(Point p, double w, double h)
	: p_(p)
	, w_(w)
	, h_(h)
{
}

void Triangle2::scale(double s)
{
	p_.x += (1 - s) * w_ / 3;
	p_.y += (1 - s) * h_ / 3;
	w_ *= s;
	h_ *= s;
}


Triangle3::Triangle3(Point p, double w, double h)
	: p_(p)
	, w_(w)
	, h_(h)
{
}

void Triangle3::scale(double s)
{
	p_.x += (1 - s) * w_ / 3;
	p_.y += (1 - s) * h_ / 3;
	w_ *= s;
	h_ *= s;
}

Triangle4::Triangle4(Point p, double w, double h)
	: p_(p)
	, w_(w)
	, h_(h)
{
}

void Triangle4::scale(double s)
{
	p_.x += (1 - s) * w_ / 3;
	p_.y += (1 - s) * h_ / 3;
	w_ *= s;
	h_ *= s;
}
