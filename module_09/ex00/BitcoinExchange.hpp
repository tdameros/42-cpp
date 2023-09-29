#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

# define DATE_LENGTH 10

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const std::string& inputFile);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(const BitcoinExchange& other);

private:
	std::map<std::string, int>	_dataBase;

	void	_fillDataBase(std::ifstream& dataBaseFile);
	bool	_isValidDate(const std::string& date);
	bool	_isDigitStr(const std::string& s);
};


#endif
