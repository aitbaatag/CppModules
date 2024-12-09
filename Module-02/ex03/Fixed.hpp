#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath> ScavTrap

class Fixed
{
private:
    int fixedPointValue;
    static const int _fractionalBits = 8; // is mean how many bits after the point (how many bits represent the fractional part)
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &other);
    Fixed(int num);
    Fixed(float num);
    Fixed &operator=(const Fixed &other);
    // Overload comparison operators
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;

    // Overload arithmetic operators
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // Overload increment/decrement operators
    Fixed &operator++();   // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed &operator--();   // Pre-decrement
    Fixed operator--(int); // Post-decrement

    // Static member functions min and max
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream &COUT, const Fixed &fixed);
#endif