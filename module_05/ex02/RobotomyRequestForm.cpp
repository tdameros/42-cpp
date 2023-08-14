#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): Form("RobotomyRequestForm",
													 "Undefined", 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target):
											 Form("RobotomyRequestForm",
												  target, 72, 45)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): Form(other)
{

}

RobotomyRequestForm::~RobotomyRequestForm(void)
{

}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	this->beExecute(executor);
	std::cout << "Vrrrrrrrrr" << std::endl;
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}