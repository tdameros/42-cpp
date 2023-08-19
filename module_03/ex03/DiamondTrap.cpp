#include <iostream>

#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap(),
								ScavTrap(),
								FragTrap(),
								_name("Unnamed")
{
	ScavTrap	scav;

	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = scav.getEnergyPoints();
	std::cout << FragTrap::_attackDamage << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const std::string name): ClapTrap(name + "_clap_name"),
												  ScavTrap(),
												  FragTrap(),
												  _name(name)
{
	ScavTrap	scav;

	std::cout << "DiamondTrap string constructor called" << std::endl;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = scav.getEnergyPoints();
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other),
													ScavTrap(other),
													FragTrap(other)
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