#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& other);
	~Character(void);

	Character&	operator=(const Character& other);

	const std::string&	getName() const;

	void	equip(AMateria* m);
	void	unequip(int idx);
	void	use(int idx, ICharacter& target);

private:
	std::string	_name;
	AMateria*	_inventory[4];

	void	_initializeInventory(void);
	void	_deleteInventory(void);
};

#endif
