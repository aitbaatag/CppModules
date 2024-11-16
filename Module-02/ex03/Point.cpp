#include "Point.hpp"

Point::Point() : x(Fixed(0)), y(Fixed(0))
{
}
Point::~Point()
{
}
Point::Point(const float xVal, const float yVal) : x(Fixed(xVal)), y(Fixed(yVal))
{
}
Point::Point(const Point &other) : x(other.x), y(other.y)
{
}
Point &Point::operator=(const Point &other)
{
    (void)other;
    return *this;
}
Fixed Point::getX() const
{
    return (x);
}
Fixed Point::getY() const
{
    return (y);
}