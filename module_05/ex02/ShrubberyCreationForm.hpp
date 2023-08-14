#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& other);

	void	execute(const Bureaucrat& executor) const;
};

#endif
