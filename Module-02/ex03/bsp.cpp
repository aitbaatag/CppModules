#include "bsp.h"
Fixed calculateArea(const Point &A, const Point &B, const Point &C)
{
    return Fixed(std::abs(
        (A.getX().toFloat() * (B.getY().toFloat() - C.getY().toFloat()) +
         B.getX().toFloat() * (C.getY().toFloat() - A.getY().toFloat()) +
         C.getX().toFloat() * (A.getY().toFloat() - B.getY().toFloat())) /
        2.0f));
}
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed areaABC = calculateArea(a, b, c);
    Fixed areaPAB = calculateArea(point, a, b);
    Fixed areaPBC = calculateArea(point, b, c);
    Fixed areaPCA = calculateArea(point, c, a);

    return (areaABC == areaPAB + areaPBC + areaPCA &&
            areaPAB > 0 && areaPBC > 0 && areaPCA > 0);
}