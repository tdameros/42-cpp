#include <iostream>
#include <limits>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name(std::string("Unnamed")),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): _name(name),
						  					_hitPoints(10),
						  					_energyPoints(10),
						  					_attackDamage(0)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = other;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " attacks "
				  << target << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount >= this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout <<"ClapTrap " << this->_name << " lost " << amount << " hit points, "
			  << "current health is " << this->_hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " gets " <<
		amount << " points of life back." << std::endl;
		if (this->_hitPoints > std::numeric_limits<unsigned int>::max() - amount)
		{
			this->_hitPoints = std::numeric_limits<unsigned int>::max();
			std::cerr << "Warning: ClapTrap " << this->_name << " hit points overflowed "
			"during repair setting hit points to " << this->_hitPoints << std::endl;
		}
		else
			this->_hitPoints += amount;
	}
}