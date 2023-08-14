#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& other);

	void	execute(const Bureaucrat& executor) const;
};

#endif
