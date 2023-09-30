#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

#include "BitcoinExchange.hpp"


static inline std::string &trim(std::string &s);
static inline std::string &ltrim(std::string &s);
static inline std::string &rtrim(std::string &s);

BitcoinExchange::BitcoinExchange(void) { }

BitcoinExchange::BitcoinExchange(const std::string& inputFile)
{
	std::ifstream	dataBaseFile(inputFile.c_str());

	if (!dataBaseFile.is_open())
		throw (OpenDatabaseException());
	_fillDataBase(dataBaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void) { }

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_dataBase = other._dataBase;
	}
	return (*this);
}

void	BitcoinExchange::convert(const std::string& inputFile)
{
	std::ifstream	file(inputFile.c_str());
	std::string		line;

	if (!file.is_open())
		throw (OpenInputFileException());
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
	size_t 			separator_index;
	char 			*endptr;
	double 			amount;

	separator_index = line.find("|");
	if (separator_index == std::string::npos)
		throw (SeparatorNotFound());
	date = line.substr(0, separator_index);
	date = trim(date);
	if (!_isValidDate(date))
		throw (InvalidDate());
	str_amount = line.substr(separator_index + 1, line.length() - date.length());
	str_amount = trim(str_amount);
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
		throw EmptyDatabaseException();
}

void	BitcoinExchange::_parseDataBaseLine(const std::string& line)
{
	size_t 		separator_index;
	std::string date;
	std::string str_price;
	double		price;
	char		*endptr;


	separator_index = line.find(",");
	if (separator_index == std::string::npos)
		return;
	date = line.substr(0, separator_index);
	date = trim(date);
	str_price = line.substr(separator_index + 1, line.length() - date.length());
	str_price = trim(str_price);
	if (str_price.length() == 0)
		return;
	price = strtod(str_price.c_str(), &endptr);
	if (errno == ERANGE || *endptr != '\0')
		return;
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

static inline std::string &trim(std::string &s)
{
	return (ltrim(rtrim(s)));
}

static inline std::string &ltrim(std::string &s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(),
									std::not1(std::ptr_fun<int, int>(std::isspace))));
	return (s);
}

static inline std::string &rtrim(std::string &s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(),
						 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return (s);
}

