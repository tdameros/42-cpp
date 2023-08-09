#include <iostream>
#include <cstdlib>

#include "Harl.hpp"

int main(void)
{
	Harl	foo;

	foo.complain("DEBUG");
	foo.complain("INFO");
	foo.complain("WARNING");
	foo.complain("ERROR");
	foo.complain("foo");
	return (EXIT_SUCCESS);
}