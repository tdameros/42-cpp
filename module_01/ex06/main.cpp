#include <cstdlib>
#include <iostream>

#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
		return (EXIT_FAILURE);
	harl.complain(std::string(argv[1]));
	return (EXIT_SUCCESS);
}