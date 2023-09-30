#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Error: invalid argument ./btc input.txt" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange	binance = BitcoinExchange("data.csv");
		binance.convert(std::string(argv[1]));
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
