#include <iostream>

#include "AMateria.hpp"

AMateria::AMateria(void): _type("Undefined")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(const std::string& type): _type(type)
{
	std::cout << "AMateria string constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& other)
{
	std::cout << "AMateria copy constructor called" << std::endl;
	*this = other;
}

AMateria::~AMateria(void)
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other._type;
	return (*this);
}

const std::string&	AMateria::getType(void) const
{
	return (this->_type);
}