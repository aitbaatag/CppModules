#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(int num)
{
    fixedPointValue = num << _fractionalBits;
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(float num)
{
    fixedPointValue = roundf(num * (1 << _fractionalBits)); // num * 256
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPointValue = other.getRawBits();
    return *this;
}
std::ostream& operator<<(std::ostream& COUT, const Fixed &fixed)
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
    return fixedPointValue >> _fractionalBits; // 
}
