#include "Fixed.hpp"

Fixed::Fixed()
{
    fixedPointValue = 0;
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fixedPointValue = other.getRawBits();
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return fixedPointValue;
}

void Fixed::setRawBits(int const raw)
{
    fixedPointValue = raw;
    std::cout << "setRawBits member function called" << std::endl;
}