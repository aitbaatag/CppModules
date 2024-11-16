#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>
#include <cmath>
#include "Fixed.hpp"
class Point
{
private:
    const Fixed x;
    const Fixed y;

public:
    Point();
    ~Point();
    Point(const Point &other);
    Point(const float xVal, const float yVal);
    Point &operator=(const Point &other);
    // Getters for x and y
    Fixed getX() const;
    Fixed getY() const;
};
#endif