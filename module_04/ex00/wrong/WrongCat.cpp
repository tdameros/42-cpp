#include <iostream>

#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << this->_type << " makes 'Miaou' sound" << std::endl;
}
