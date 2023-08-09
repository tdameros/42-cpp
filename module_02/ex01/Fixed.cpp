#include <iostream>
#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed(): _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	_rawBits = number << _fractionalBits;
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	_rawBits = roundf(number * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		_rawBits = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void	Fixed::setRawBits(const int raw)
{
	this->_rawBits = raw;
}

int Fixed::toInt() const
{
	return (_rawBits >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float) _rawBits / (1 << _fractionalBits));
}

std::ostream& operator<<(std::ostream &os, const Fixed &fixed)
{
	return (os << fixed.toFloat());
}