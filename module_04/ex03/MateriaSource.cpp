#include <iostream>

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "MateriaSource default constructor called" << std::endl;
	this->_initializeMaterias();
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "MateriaSource destructor called" << std::endl;
	this->_deleteMaterias();
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_deleteMaterias();
		for (int i = 0; i < 4; i++)
		{
			if (other._materias[i] != NULL)
				this->_materias[i] = other._materias[i]->clone();
			else
				this->_materias[i] = NULL;
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] == NULL)
		{
			this->_materias[i] = materia;
			return;
		}

	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && this->_materias[i]->getType() == type)
			return (this->_materias[i]->clone());
	}
	return (NULL);
}

void	MateriaSource::_initializeMaterias(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

void	MateriaSource::_deleteMaterias(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL)
			delete this->_materias[i];
	}
}
