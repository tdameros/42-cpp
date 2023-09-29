#include <iostream>
#include <fstream>
#include <cstdlib>

#include "BitcoinExchange.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Invalid argument: ./btc input.txt" << std::endl;
		return (EXIT_FAILURE);
	}
	BitcoinExchange	binance = BitcoinExchange("data.csv");
	binance.convert(std::string(argv[1]));
	return (EXIT_SUCCESS);
}
