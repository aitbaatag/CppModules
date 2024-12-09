#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointValue = 0;
}
Fixed::Fixed(int num)
{
    fixedPointValue = num << _fractionalBits; // num * 256
}
Fixed::Fixed(float num)
{
    fixedPointValue = roundf(num * 256);
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &other)
{
    fixedPointValue = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        fixedPointValue = other.getRawBits();
    return *this;
}

// Overload arithmetic operators
Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.fixedPointValue = (fixedPointValue * other.fixedPointValue) >> _fractionalBits;
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    Fixed result;
    result.fixedPointValue = (fixedPointValue / other.fixedPointValue) << _fractionalBits;
    return result;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.fixedPointValue = fixedPointValue + other.fixedPointValue;
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.fixedPointValue = fixedPointValue - other.fixedPointValue;
    return result;
}

// Overload increment/decrement operators
Fixed &Fixed::operator++()
{
    fixedPointValue += 1;
    return *this;
}
Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    fixedPointValue += 1;
    return temp;
}
Fixed &Fixed::operator--()
{
    fixedPointValue -= 1;
    return *this;
}
Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    fixedPointValue -= 1;
    return temp;
}
// Overload comparison operators
bool Fixed::operator>(const Fixed &other) const
{
    return fixedPointValue > other.fixedPointValue;
}
bool Fixed::operator<(const Fixed &other) const
{
    return fixedPointValue < other.fixedPointValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return fixedPointValue >= other.fixedPointValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return fixedPointValue <= other.fixedPointValue;
}
bool Fixed::operator==(const Fixed &other) const
{
    return fixedPointValue == other.fixedPointValue;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return fixedPointValue != other.fixedPointValue;
}
// Static member functions min and max
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed)
{
    COUT << fixed.toFloat();
    return COUT;
}

int Fixed::getRawBits(void) const
{
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedPointValue = raw;
}
float Fixed::toFloat(void) const
{
    return (float)fixedPointValue / (1 << _fractionalBits); // fixedPointValue / 256
}

int Fixed::toInt(void) const
{
    return fixedPointValue >> _fractionalBits;
}
