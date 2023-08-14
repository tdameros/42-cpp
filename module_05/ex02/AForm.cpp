#include <iostream>

#include "AForm.hpp"

Form::Form(void): _name("Undefined"), _target("Undefined"), _isSigned(false),
				  _requiredGradeToSign(150), _requiredGradeToExecute(150)
{

}

Form::Form(const std::string name, const std::string target,
		   const unsigned int requiredGradeToSign,
		   const unsigned int requiredGradeToExecute):
		   _name(name), _target(target),
		   _isSigned(false), _requiredGradeToSign(requiredGradeToSign),
		   _requiredGradeToExecute(requiredGradeToExecute)
{
	if (requiredGradeToSign < 1 || requiredGradeToExecute < 1)
		throw GradeTooHighException();
	if (requiredGradeToSign > 150 || requiredGradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other): _name(other._name), _target(other._target),
							   _requiredGradeToSign(other._requiredGradeToSign),
							   _requiredGradeToExecute(other._requiredGradeToExecute)
{
	*this = other;
}

Form::~Form(void)
{

}

Form&	Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

void	Form::beExecute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw UnsignedFormException();
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

std::string Form::getTarget(void) const
{
	return (this->_target);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

unsigned int Form::getRequiredGradeToSign(void) const
{
	return (this->_requiredGradeToSign);
}

unsigned int Form::getRequiredGradeToExecute(void) const
{
	return (this->_requiredGradeToExecute);
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it should be between 1 and 150 (inclusive)");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it should be between 1 and 150 (inclusive)");
}

const char*	Form::UnsignedFormException::what() const throw()
{
	return ("The form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	if (form.getIsSigned())
		os << form.getName() << " form is signed";
	else
		os << form.getName() << " form is not signed";
	os << "\n(required grade to sign: " << form.getRequiredGradeToSign() << ")"
	<< "\n(required grade to execute: " << form.getRequiredGradeToExecute()
	<< ", target: " << form.getTarget() << ")";
	return (os);
}