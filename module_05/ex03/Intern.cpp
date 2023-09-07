#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{

}

Intern::Intern(const Intern& other)
{
	*this = other;
}

Intern::~Intern(void)
{

}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm*	forms[] = {new ShrubberyCreationForm(target),
					   new RobotomyRequestForm(target),
					   new PresidentialPardonForm(target)};
	const std::string	formNames[]  = {"shrubbery creation",
					   					"robotomy request",
					   					"presidential pardon"};
	AForm*	resultForm = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
			resultForm = forms[i];
		else
			delete forms[i];
	}
	return (resultForm);
}