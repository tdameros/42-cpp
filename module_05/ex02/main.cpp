#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				belica = Bureaucrat("Belica", 1);
	Bureaucrat				lea = Bureaucrat("Lea", 149);
	PresidentialPardonForm	presidentialForm("Zed");
	RobotomyRequestForm		robotForm("Marvin");
	ShrubberyCreationForm	shrubberyForm("groot");

	belica.signForm(presidentialForm);
	lea.executeForm(presidentialForm);
	belica.executeForm(presidentialForm);

	belica.signForm(robotForm);
	lea.executeForm(robotForm);
	belica.executeForm(robotForm);

	belica.signForm(shrubberyForm);
	lea.executeForm(shrubberyForm);
	belica.executeForm(shrubberyForm);

	return (0);
}
