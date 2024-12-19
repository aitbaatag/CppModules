#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
    int fixedPointValue;
    static const int _fractionalBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed(int num);
    Fixed(float num);
    Fixed &operator=(const Fixed &other);
    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);
#endif