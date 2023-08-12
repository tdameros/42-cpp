#include <iostream>

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat	belica = Bureaucrat("Belica", 150);

	std::cout << belica << std::endl;
	belica.incrementGrade();
	std::cout << belica << std::endl;
	belica.decrementGrade();
	std::cout << belica << std::endl;
	try
	{
		belica.decrementGrade();
	}
	catch (Bureaucrat::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat mea = Bureaucrat("Mea", 1);
	try
	{
		mea.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << mea << std::endl;
	return (0);
}
