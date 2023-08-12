#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void): _name("Unnamed")
{
	std::cout << "Character default constructor called" << std::endl;
	this->_initializeInventory();
}

Character::Character(const std::string& name): _name(name)
{
	std::cout << "Character string constructor called" << std::endl;
	this->_initializeInventory();
}

Character::Character(const Character& other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character::~Character(void)
{
	std::cout << "Character destructor called" << std::endl;
	this->_deleteInventory();
}

Character&	Character::operator=(const Character& other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_deleteInventory();
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i] != NULL)
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

const std::string&	Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
	{
		std::cerr << "Invalid inventory index" << std::endl;
		return ;
	}
	this->_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3 || this->_inventory[idx] == NULL)
	{
		std::cerr << "Invalid inventory index" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}

void	Character::_initializeInventory(void)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

void	Character::_deleteInventory(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
	}
}