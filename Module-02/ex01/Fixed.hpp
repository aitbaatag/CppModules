#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixedPointValue;
        static const int _fractionalBits = 8; // is mean how many bits after the point (how many bits represent the fractional part)
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed &other);
        Fixed(int num);
        Fixed(float num);
        Fixed& operator=(Fixed& other);
        float toFloat( void ) const;
        int toInt( void ) const;
};
#endif