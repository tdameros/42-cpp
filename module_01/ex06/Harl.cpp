#include <iostream>
#include <cstdlib>
#include <cstddef>

#include "Harl.hpp"

Harl::Harl()
{
	this->_strLevel[0] = "DEBUG";
	this->_strLevel[1] = "INFO";
	this->_strLevel[2] = "WARNING";
	this->_strLevel[3] = "ERROR";
}

void	Harl::complain(std::string level)
{
	switch (this->getLevel(level))
	{
		case 0:
			this->debug();
			break;
		case 1:
			this->info();
			break;
		case 2:
			this->warning();
			break;
		case 3:
			this->error();
			break;
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]"
					  << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my "
			  << "7XL-double-cheese-triple-pickle-special-ketchup burger."
			  << std::endl
			  << "I really do !"
			  << std::endl << std::endl;
	this->info();
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money."
			  << std::endl
			  << "You didn’t put enough bacon in my burger !"
			  << std::endl
			  << "If you did, I wouldn’t be asking for more !"
			  << std::endl << std::endl;
	this->warning();
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free."
			  << std::endl
			  << "I’ve been coming for years whereas "
			  << "you started working here since last month."
			  << std::endl << std::endl;
	this->error();
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now."
			  << std::endl << std::endl;
}

int	Harl::getLevel(std::string level)
{
	int	size;

	size = sizeof(this->_strLevel) / sizeof(*this->_strLevel);
	for (int i = 0; i < size; i++)
	{
		if (this->_strLevel[i] == level)
			return (i);
	}
	return (-1);
}
