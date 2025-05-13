/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 18:01:21 by serferna          #+#    #+#             */
/*   Updated: 2025/05/09 18:01:21 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include <iostream>

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    int scalingFactor = 1 << _fractionalBits;
    _value = static_cast<int>(roundf(value * scalingFactor));
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;

    if (this != &other)
        return *this;

    _value = other._value;
    return *this;
}

bool Fixed::operator>(const Fixed& other) const
{
    std::cout << "Comparison operator > called" << std::endl;

    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const
{
    std::cout << "Comparison operator < called" << std::endl;

    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const
{
    std::cout << "Comparison operator >= called" << std::endl;

    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const
{
    std::cout << "Comparison operator <= called" << std::endl;

    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const
{
    std::cout << "Comparison operator == called" << std::endl;

    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const
{
    std::cout << "Comparison operator != called" << std::endl;

    return _value != other._value;
}

Fixed Fixed::operator+(const Fixed& other) const
{
    std::cout << "Arithmetic operator + called" << std::endl;

    Fixed result;
    result.setRawBits(_value + other._value);
    return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
    std::cout << "Arithmetic operator - called" << std::endl;

    Fixed result;
    result.setRawBits(_value - other._value);
    return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
    std::cout << "Arithmetic operator * called" << std::endl;

    Fixed result;
    result.setRawBits((_value * other._value) >> _fractionalBits);
    return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
    std::cout << "Arithmetic operator / called" << std::endl;

    if (other._value == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    Fixed result;
    result.setRawBits((_value << _fractionalBits) / other._value);
    return result;
}

Fixed& Fixed::operator++()
{
    std::cout << "Pre-increment operator called" << std::endl;

    ++_value;
    return *this;
}

Fixed Fixed::operator++(int)
{
    std::cout << "Post-increment operator called" << std::endl;

    Fixed temp = *this;
    ++_value;
    return temp;
}

Fixed& Fixed::operator--()
{
    std::cout << "Pre-decrement operator called" << std::endl;

    --_value;
    return *this;
}

Fixed Fixed::operator--(int)
{
    std::cout << "Post-decrement operator called" << std::endl;

    Fixed temp = *this;
    --_value;
    return temp;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return _value;
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

float Fixed::toFloat() const
{
    std::cout << "toFloat member function called" << std::endl;

    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const
{
    std::cout << "toInt member function called" << std::endl;

    return _value >> _fractionalBits;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    std::cout << "Min function called" << std::endl;

    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    std::cout << "Min function called" << std::endl;

    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    std::cout << "Max function called" << std::endl;

    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    std::cout << "Max function called" << std::endl;

    return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
