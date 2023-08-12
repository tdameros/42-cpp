#include <iostream>

#include "Animal.hpp"

Animal::Animal(): _type("Undefined")
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const std::string type): _type(type)
{
	std::cout << "Animal string constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << this->_type << " makes 'Undefined' sound" << std::endl;
}
