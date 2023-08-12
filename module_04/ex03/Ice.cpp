#include <iostream>

#include "AMateria.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void): AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice::~Ice(void)
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice&	Ice::operator=(const Ice& other)
{
	std::cout << "Ice assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

const std::string&	Ice::getType(void) const
{
	return (this->_type);
}

AMateria*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}