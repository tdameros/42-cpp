#include <iostream>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Undefined"), _grade(150)
{

}

Bureaucrat::Bureaucrat(const std::string name,
					   const unsigned int grade): _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{

}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

void	Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getIsSigned())
	{
		std::cout << this->getName() << " couldn’t sign "
				  << form.getName() << " because the form is already signed."
				  << std::endl;
	}
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->getName() << " signed " << form.getName()
					  << std::endl;
		}
		catch (Form::GradeTooLowException& e)
		{
			std::cout << this->getName() << " couldn’t sign "
					  << form.getName() << " because its grade is too low."
					  << std::endl;
		}
	}
}

void	Bureaucrat::executeForm(const Form& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (Form::UnsignedFormException& e)
	{
		std::cout << this->getName() << " couldn’t execute "
				  << form.getName() << " because the form is unsigned."
				  << std::endl;
	}
	catch (Form::GradeTooLowException& e)
	{
		std::cout << this->getName() << " couldn’t execute "
				  << form.getName() << " because its grade is too low."
				  << std::endl;
	}
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it should be between 1 and 150 (inclusive)");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it should be between 1 and 150 (inclusive)");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
