#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	~MateriaSource(void);

	MateriaSource&	operator=(const MateriaSource& other);

	void		learnMateria(AMateria*);
	AMateria*	createMateria(const std::string& type);

private:
	AMateria*	_materias[4];

	void		_initializeMaterias(void);
	void		_deleteMaterias(void);
};


#endif
