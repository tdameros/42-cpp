#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <ctype.h>
#include <cerrno>
#include <cstdlib>
#include <cmath>

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

void	ScalarConvert::convert(const std::string &literal)
{
	char	*endptr;
	bool	isPossible;

	double conversion = strtod(literal.c_str(), &endptr);
	if (errno != ERANGE
		&& (*endptr == '\0' || (*endptr == 'f' && *(endptr + 1) == '\0')))
		isPossible = true;
	else
		isPossible = false;
	if (!isPossible && literal.length() == 1)
	{
		conversion = static_cast<char>(literal[0]);
		isPossible = true;
	}
	ScalarConvert::_printCharConversion(conversion, isPossible);
	ScalarConvert::_printIntConversion(conversion, isPossible);
	ScalarConvert::_printFloatConversion(conversion, isPossible);
	ScalarConvert::_printDoubleConversion(conversion, isPossible);
}

void	ScalarConvert::_printCharConversion(const double conversion, bool isPossible)
{
	if (!isPossible || std::isnan(conversion) || conversion > std::numeric_limits<char>::max()
		|| conversion < std::numeric_limits<char>::min())
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(static_cast<char>(conversion)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(conversion) << "'" << std::endl;
}

void	ScalarConvert::_printIntConversion(const double conversion, bool isPossible)
{
	if (!isPossible || std::isnan(conversion) ||conversion > std::numeric_limits<int>::max()
		|| conversion < std::numeric_limits<int>::min())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(conversion) << std::endl;
}

void	ScalarConvert::_printFloatConversion(const double conversion, bool isPossible)
{
	if (!isPossible || (!ScalarConvert::_isInff(conversion)
	&& (conversion > std::numeric_limits<float>::max()
	|| conversion < -std::numeric_limits<float>::max())))
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(2) << "float: "
		<< static_cast<float>(conversion) << "f" << std::endl;
}

void	ScalarConvert::_printDoubleConversion(const double conversion, bool isPossible)
{
	if (!isPossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << std::fixed << std::setprecision(2) << "double: "
		<< static_cast<double>(conversion) << std::endl;
}

bool ScalarConvert::_isInf(const double number)
{
	return (number == -std::numeric_limits<double>::infinity()
		|| number == std::numeric_limits<double>::infinity());
}

bool ScalarConvert::_isInff(const float number)
{
	return (number == -std::numeric_limits<float>::infinity()
		|| number == std::numeric_limits<float>::infinity());
}
