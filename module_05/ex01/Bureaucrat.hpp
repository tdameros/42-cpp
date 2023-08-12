#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, const unsigned int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);

	Bureaucrat&	operator=(const Bureaucrat &other);

	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form& form);

	std::string		getName(void) const;
	unsigned int	getGrade(void) const;


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
	unsigned int		_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
