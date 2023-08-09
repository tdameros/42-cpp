#include <iostream>

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(),
								FragTrap(),
								ScavTrap(),
								_name("Unnamed")
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	std::cout << FragTrap::_attackDamage << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"),
												  FragTrap(name),
												  ScavTrap(name),
												  _name(name)
{
	std::cout << "DiamondTrap string constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	*this = other;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	if (this != &other)
	{
		ClapTrap::_name = other.ClapTrap::_name;
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name: " << this->_name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::_name << std::endl;

	std::cout << this->_name << std::endl;
	std::cout << this->_hitPoints << std::endl;
	std::cout << this->_energyPoints << std::endl;
	std::cout << this->_attackDamage << std::endl;
}