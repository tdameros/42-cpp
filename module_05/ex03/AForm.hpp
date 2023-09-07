#ifndef FORM_HPP
# define FORM_HPP

# include <string>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
	AForm(void);
	AForm(const std::string name, const std::string target,
		  const unsigned int requiredGradeToSign,
		  const unsigned int requiredGradeToExecute);
	AForm(const AForm &other);
	virtual ~AForm(void);

	AForm&	operator=(const AForm& other);

	virtual void	execute(const Bureaucrat& executor) const = 0;
	void			beExecute(const Bureaucrat& executor) const;
	void			beSigned(const Bureaucrat& bureaucrat);

	std::string		getName(void) const;
	std::string 	getTarget(void) const;
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

	class UnsignedFormException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	const std::string	_name;
	const std::string	_target;
	bool				_isSigned;
	const unsigned int	_requiredGradeToSign;
	const unsigned int	_requiredGradeToExecute;
};

std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif
