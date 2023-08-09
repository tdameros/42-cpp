#include <iostream>
#include <limits>

#include "FragTrap.hpp"

int    main(void)
{
	{
		FragTrap	Frag("Frag");
		FragTrap    trap("Trap");

		Frag.attack("Trap");
		trap.beRepaired(2);
		trap.takeDamage(112);

		// Can't attack because he is dead
		trap.attack("Frag");
		Frag.beRepaired(std::numeric_limits<unsigned int>::max());
		Frag.takeDamage(100);
		Frag.takeDamage(std::numeric_limits<unsigned int>::max());
		Frag = FragTrap("Frag");
		for (int i = 0; i < 52; i++)
			Frag.attack("Bidule");
		trap = FragTrap(Frag);
		trap.takeDamage(100);
		Frag = trap;
		trap.takeDamage(100);
	}
	return (0);
}