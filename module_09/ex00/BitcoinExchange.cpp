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

void	BitcoinExchange::convert(const std::string& inputFile)
{
	std::ifstream	file(inputFile.c_str());
	std::string		line;

	if (!file.is_open())
		throw (std::exception());
	getline(file, line);
	while (getline(file, line))
	{
		try
		{
			_convertLine(line);
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::_convertLine(const std::string& line)
{
	std::string		date;
	std::string		str_amount;
	size_t 			pipe_index;
	char 			*endptr;
	double 			amount;

	pipe_index = line.find("|");
	if (pipe_index == std::string::npos)
		throw (SeparatorNotFound());
	date = line.substr(0, pipe_index);
	if (!_isValidDate(date))
		throw (InvalidDate());
	str_amount = line.substr(pipe_index + 1, line.length() - date.length());
	if (str_amount.length() == 0)
		throw (AmountNotFound());
	amount = strtod(str_amount.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0' || amount < 0 || amount > 1000)
		throw (AmountInvalidRange());
	std::map<std::string, double>::iterator it = _dataBase.lower_bound(date);
	std::cout << date << " => " << amount << " = " << amount * it->second << std::endl;
}

void	BitcoinExchange::_fillDataBase(std::ifstream& dataBaseFile)
{
	std::string	line;

	getline(dataBaseFile, line);
	while (getline(dataBaseFile, line))
	{
		_parseDataBaseLine(line);
	}
	if (_dataBase.size() == 0)
		throw EmptyDataBaseException();
}

void	BitcoinExchange::_parseDataBaseLine(const std::string& line)
{
	size_t 		comma_index;
	std::string date;
	std::string str_price;
	double		price;
	char		*endptr;


	comma_index = line.find(",");
	if (comma_index == std::string::npos)
		return;
	date = line.substr(0, comma_index);
	str_price = line.substr(comma_index + 1, line.length() - date.length());
	if (str_price.length() == 0)
		return;
	price = strtod(str_price.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
	{
		return;
	}
//	std::cout << "Date: " << date << std::endl;
//	std::cout << "Price: " << price << std::endl;
	_dataBase.insert(std::make_pair(date, price));
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
	return (_isCalendarDate(atoi(year.c_str()),
							atoi(month.c_str()),
							atoi(day.c_str())));
}

bool	BitcoinExchange::_isDigitStr(const std::string &s)
{
	for (size_t i = 0; i < s.length(); i++)
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
	if (day > 31 && (month == JANUARY || month == MARCH || month == MAY ||
					 month == JULY || month == AUGUST || month == OCTOBER
					 || month == DECEMBER))
		return (false);
	if (day > 30 && (month == APRIL || month == JUNE || month == SEPTEMBER ||
					 month == NOVEMBER))
		return (false);
	if (day > 29 && month == FEBRUARY && _isLeap(year))
		return (false);
	if (day > 28 && month == FEBRUARY && !_isLeap(year))
		return (false);
	return (true);
}

bool	BitcoinExchange::_isLeap(const unsigned int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
