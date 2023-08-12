#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	belica = Bureaucrat("Belica", 42);
	Form		adm = Form("adm", 42, 42);

	std::cout << adm << std::endl;
	belica.signForm(adm);
	belica.signForm(adm);
	try
	{
		Form	invalidForm("InvalidForm", 0, 0);
	}
	catch (Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form	invalidForm("InvalidForm", 1000, 160);
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat	lea = Bureaucrat("Lea", 43);
	Form		identityForm = Form("ID", 10, 11);
	lea.signForm(identityForm);
	return (0);
}
