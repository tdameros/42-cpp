#include <iostream>
#include <limits>

#include "ScavTrap.hpp"

int    main(void)
{
	{
		ClapTrap    clap("Clap");
		ClapTrap    trap("Trap");

		clap.attack("Trap");
		trap.beRepaired(2);
		trap.takeDamage(12);

		// Can't attack because he is dead
		trap.attack("Clap");
		clap.beRepaired(std::numeric_limits<unsigned int>::max());
		clap.takeDamage(100);
		clap.takeDamage(std::numeric_limits<unsigned int>::max());
		clap = ClapTrap("Clap");
		for (int i = 0; i < 12; i++)
			clap.attack("Bidule");
		trap = ClapTrap(clap);
		trap.takeDamage(100);
		clap = trap;
		trap.takeDamage(100);
	}
	{
		ScavTrap    scav("Scav");
		ScavTrap    trap("Trap");

		scav.attack("Trap");
		trap.beRepaired(2);
		trap.takeDamage(112);

		// Can't attack because he is dead
		trap.attack("Scav");
		scav.beRepaired(std::numeric_limits<unsigned int>::max());
		scav.takeDamage(100);
		scav.takeDamage(std::numeric_limits<unsigned int>::max());
		scav = ScavTrap("Scav");
		for (int i = 0; i < 52; i++)
			scav.attack("Bidule");
		trap = ScavTrap(scav);
		trap.takeDamage(100);
		scav = trap;
		trap.takeDamage(100);
		scav.guardGate();
	}
	return (0);
}