#include <string>
#include <iostream>

#include "ScalarConvert.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Invalid argument" << std::endl;
		return (1);
	}
	std::string	literal = argv[1];
	ScalarConvert::convert(literal);
	return (0);
}
