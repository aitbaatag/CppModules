#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
    private:
        int fixedPointValue;
        static const int _fractionalBits = 8; // is mean how many bits after the point (how many bits represent the fractional part)
    public:
        Fixed();
        ~Fixed();
        Fixed(Fixed &other);
        Fixed& operator=(Fixed& other);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};
#endif