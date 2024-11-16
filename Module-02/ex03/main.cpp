#include <iostream>
#include "bsp.h"
#include "Point.hpp"

int main()
{
    Point A(0, 0);
    Point B(5, 0);
    Point C(0, 5);
    Point P(4, 0);

    if (bsp(A, B, C, P))
    {
        std::cout << "Point is inside the triangle.\n";
    }
    else
    {
        std::cout << "Point is outside the triangle.\n";
    }

    return 0;
}
