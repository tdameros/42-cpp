#include <iostream>

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("Undefined")
{
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(const std::string type): _type(type)
{
	std::cout << "AAnimal string constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = other;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "AAnimal assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
