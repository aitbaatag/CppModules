#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const int num)
{
    fixedPointValue = num;
    std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed(const float num)
{
    fixedPointValue = roundf(value * (1 << _fractionalBits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    fixedPointValue = other.getRawBits();
}

Fixed& Fixed::operator=(Fixed& other)
{
    std::cout << "Assignation operator called" << std::endl;
    fixedPointValue = other.getRawBits();
    return *this;
}

float Fixed::toFloat(void) const
{
    return (float)fixedPointValue / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return fixedPointValue >> _fractionalBits;
}
