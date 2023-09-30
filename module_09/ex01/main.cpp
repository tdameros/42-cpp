#include <iostream>
#include <fstream>
#include <cstdlib>

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: invalid argument" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		RPN	calculator = RPN();
		std::cout << calculator.calculate(std::string(argv[1])) << std::endl;
	}
	catch (RPN::ExpressionException& e)
	{
		std::cout << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
