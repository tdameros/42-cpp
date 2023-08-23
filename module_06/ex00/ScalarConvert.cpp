#include <iostream>
#include <cstdlib>
#include <string>
#include <cerrno>
#include <ctype.h>
#include <limits>

#include "ScalarConvert.hpp"

ScalarConvert::ScalarConvert(void)
{

}

ScalarConvert::ScalarConvert(const ScalarConvert &other)
{
	*this = other;
}

ScalarConvert::~ScalarConvert(void)
{

}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &other)
{
	if (this != &other)
	{

	}
	return (*this);
}

void	ScalarConvert::convert(std::string &literal)
{
	char	*endptr;

	double conversion = strtod(literal.c_str(), &endptr);
	if (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0'))
	{
		ScalarConvert::_printCharConversion(conversion);
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
		std::cout << "float: " << static_cast<float>(conversion) << "f" << std::endl;
		std::cout << "double: " << conversion << std::endl;
	}
	else
		std::cout << "Invalid" << std::endl;
	std::cout << errno << std::endl;
	(void) conversion;
}

void	ScalarConvert::_printCharConversion(double conversion)
{
	if (conversion > std::numeric_limits<char>::max())
		std::cout << "char: Overflow" << std::endl;
	else if (conversion < std::numeric_limits<char>::min())
		std::cout << "char: Underflow" << std::endl;
	else if (!isprint(static_cast<char>(conversion)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
}

