#include <iostream>
#include <string>
#include <fstream>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{

}

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
{
	std::ifstream	dataBaseFile(inputFile.c_str());

	if (!dataBaseFile.is_open())
		throw (std::exception());
	_fillDataBase(dataBaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

void BitcoinExchange::_fillDataBase(std::ifstream& dataBaseFile)
{
	std::string	line;

	getline(dataBaseFile, line);
	while (getline(dataBaseFile, line))
	{
		std::cout << line << std::endl;
		_isValidDate(line);
	}

}

bool	BitcoinExchange::_isValidDate(const std::string &date)
{
	std::string	year;
	std::string	month;
	std::string	day;

	if (date.length() != DATE_LENGTH || date[4] != '-' || date[7] != '-')
		return (false);
	year = date.substr(0, 4);
	month = date.substr(5, 2);
	day = date.substr(8, 2);
	if (!_isDigitStr(year) || !_isDigitStr(month) || !_isDigitStr(day))
		return (false);
	std::cout << year << std::endl;
	std::cout << month << std::endl;
	std::cout << day << std::endl;
	return (true);
}

bool	BitcoinExchange::_isDigitStr(const std::string &s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_isCalendarDate(const unsigned int year,
										 const unsigned int month,
										 const unsigned int day)
{
	if (!(month >= 1 && month <= 12) || day == 0)
		return (false);
	if (month % 2 == 1 && day > 31)
		return (false);

}
