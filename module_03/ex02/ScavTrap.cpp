#include <iostream>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap string constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << this->_name << " attacks "
				  << target << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is enter in gate keeper mode" \
			  << std::endl;
}