#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap string constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string &target)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << this->_name << " attacks "
				  << target << ", causing " << this->_attackDamage
				  << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high fives." \
			  << std::endl;
}