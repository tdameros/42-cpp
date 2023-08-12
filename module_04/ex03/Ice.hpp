#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
public:
	Ice(void);
	Ice(const Ice& other);
	~Ice(void);

	Ice&	operator=(const Ice& other);

	const std::string&	getType(void) const;

	AMateria*	clone(void) const;
	void		use(ICharacter& target);
};

#endif
