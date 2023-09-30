#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

# define DATE_LENGTH 10

enum e_months
{
	JANUARY = 1,
	FEBRUARY = 2,
	MARCH = 3,
	APRIL = 4,
	MAY = 5,
	JUNE = 6,
	JULY = 7,
	AUGUST = 8,
	SEPTEMBER = 9,
	OCTOBER = 10,
	NOVEMBER = 11,
	DECEMBER = 12,
};

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string& inputFile);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange& other);

	void	convert(const std::string& inputFile);

	class OpenDatabaseException : public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: failed to open the database"); };
	};

	class EmptyDatabaseException : public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: empty database"); };
	};

	class OpenInputFileException : public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: failed to open the input file"); };
	};

	class SeparatorNotFound : public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: separator not found"); };
	};

	class InvalidDate: public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: invalid date"); };
	};

	class AmountNotFound: public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: amount not found"); };
	};

	class AmountInvalidRange: public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: amount invalid range (0:1000)"); };
	};

private:
	std::map<std::string, double>	_dataBase;

	void	_convertLine(const std::string& line);
	void	_parseDataBaseLine(const std::string& line);
	void	_fillDataBase(std::ifstream& dataBaseFile);
	bool	_isValidDate(const std::string& date);
	bool	_isDigitStr(const std::string& s);
	bool	_isLeap(const unsigned int year);
	bool	_isCalendarDate(const unsigned int year,
							const unsigned int month,
							const unsigned int day);
};


#endif
