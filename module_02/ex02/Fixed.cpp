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
	std::cout << "Int constructor called" << std::endl;
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
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed&	Fixed::operator++(void)
{
	this->_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->_rawBits += 1;
	return (temp);
}

Fixed&	Fixed::operator--(void)
{
	this->_rawBits += 1;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->_rawBits += 1;
	return (temp);
}

bool	Fixed::operator<(const Fixed& f2) const
{
	return (this->getRawBits() < f2.getRawBits());
}

bool	Fixed::operator>(const Fixed& f2) const
{
	return (this->getRawBits() > f2.getRawBits());
}

bool	Fixed::operator<=(const Fixed& f2) const
{
	return (this->getRawBits() <= f2.getRawBits());
}

bool	Fixed::operator>=(const Fixed& f2) const
{
	return (this->getRawBits() >= f2.getRawBits());
}

bool	Fixed::operator==(const Fixed& f2) const
{
	return (this->getRawBits() == f2.getRawBits());
}

bool	Fixed::operator!=(const Fixed& f2) const
{
	return (this->getRawBits() != f2.getRawBits());
}

Fixed	Fixed::operator+(const Fixed& f2) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() + f2.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(const Fixed& f2) const
{
	Fixed	result;

	result.setRawBits(this->getRawBits() - f2.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(const Fixed& f2) const
{
	Fixed	result;
	int 	newRawBits;

	newRawBits = roundf((float)this->getRawBits() * f2.getRawBits()
				 / (1 << this->_fractionalBits));
	result.setRawBits(newRawBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed& f2) const
{
	Fixed	result;
	int 	newRawBits;

	newRawBits = roundf((float)this->getRawBits() / f2.getRawBits()
				 * (1 << this->_fractionalBits));
	result.setRawBits(newRawBits);
	return (result);
}

Fixed&	Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

const Fixed&	Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f2);
	return (f1);
}

Fixed&	Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
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

int	Fixed::toInt() const
{
	return (_rawBits >> _fractionalBits);
}

float	Fixed::toFloat() const
{
	return ((float) _rawBits / (1 << _fractionalBits));
}

std::ostream&	operator<<(std::ostream &os, const Fixed &fixed)
{
	return os << fixed.toFloat();
}
