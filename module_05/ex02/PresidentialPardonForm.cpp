#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): Form("PresidentialPardonForm",
														 "Undefined",
														 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
											 Form("PresidentialPardonForm",
												  target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): Form(other)
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