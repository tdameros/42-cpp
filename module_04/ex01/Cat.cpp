#include <iostream>

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat&	Cat::operator=(const Cat& other)
{
	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << this->_type << " makes 'Miaou' sound" << std::endl;
}
