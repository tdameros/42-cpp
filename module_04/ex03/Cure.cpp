#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void): AMateria("cure")
{
	std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure&	Cure::operator=(const Cure& other)
{
	std::cout << "Cure assignment operator called" << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

const std::string&	Cure::getType(void) const
{
	return (this->_type);
}

AMateria*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}