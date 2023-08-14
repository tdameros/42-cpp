#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("PresidentialPardonForm",
															"Undefined",
															25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
		AForm("PresidentialPardonForm",
			  target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other)
{

}

PresidentialPardonForm::~PresidentialPardonForm(void)
{

}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		*this = other;
	}
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	this->beExecute(executor);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox"
			   << std::endl;
}