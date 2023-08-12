#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const std::string name, const unsigned int requiredGradeToSign,
		 const unsigned int requiredGradeToExecute);
	Form(const Form &other);
	~Form(void);

	Form&	operator=(const Form& other);

	void			beSigned(const Bureaucrat& bureaucrat);

	std::string		getName(void) const;
	bool			getIsSigned(void) const;
	unsigned int	getRequiredGradeToSign(void) const;
	unsigned int	getRequiredGradeToExecute(void) const;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	const std::string	_name;
	bool				_isSigned;
	const unsigned int	_requiredGradeToSign;
	const unsigned int	_requiredGradeToExecute;
};

std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
