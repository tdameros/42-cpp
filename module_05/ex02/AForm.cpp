#include <iostream>

#include "AForm.hpp"

AForm::AForm(void): _name("Undefined"), _target("Undefined"), _isSigned(false),
					_requiredGradeToSign(150), _requiredGradeToExecute(150)
{

}

AForm::AForm(const std::string name, const std::string target,
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

AForm::AForm(const AForm &other): _name(other._name), _target(other._target),
								  _isSigned(other._isSigned),
								  _requiredGradeToSign(other._requiredGradeToSign),
								  _requiredGradeToExecute(other._requiredGradeToExecute)
{
	*this = other;
}

AForm::~AForm(void)
{

}

AForm&	AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getRequiredGradeToSign())
		throw GradeTooLowException();
	this->_isSigned = true;
}

void	AForm::beExecute(const Bureaucrat& executor) const
{
	if (!this->getIsSigned())
		throw UnsignedFormException();
	if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw GradeTooLowException();
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

std::string AForm::getTarget(void) const
{
	return (this->_target);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

unsigned int AForm::getRequiredGradeToSign(void) const
{
	return (this->_requiredGradeToSign);
}

unsigned int AForm::getRequiredGradeToExecute(void) const
{
	return (this->_requiredGradeToExecute);
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high, it should be between 1 and 150 (inclusive)");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low, it should be between 1 and 150 (inclusive)");
}

const char*	AForm::UnsignedFormException::what() const throw()
{
	return ("The form is not signed");
}

std::ostream&	operator<<(std::ostream& os, const AForm& form)
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