#include <iostream>

#include "DiamondTrap.hpp"

int    main(void)
{
	DiamondTrap diamondTrap = DiamondTrap("Marvin");

	diamondTrap.whoAmI();
	diamondTrap.attack("Monster");
	return (0);
}