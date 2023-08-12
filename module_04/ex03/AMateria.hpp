#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& other);
	virtual ~AMateria(void);

	AMateria&	operator=(const AMateria& other);

	const std::string&	getType(void) const; //Returns the materia type

	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target) = 0;

protected:
	std::string	_type;
};

#endif