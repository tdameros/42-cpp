#ifndef SCALARCONVERT_HPP
# define SCALARCONVERT_HPP

# include <string>

class ScalarConvert
{
public:
	ScalarConvert(void);
	ScalarConvert(const ScalarConvert& other);
	~ScalarConvert(void);

	ScalarConvert	&operator=(const ScalarConvert& other);

	static void	convert(const std::string& literal);

private:
	static void	_printCharConversion(const double conversion, bool isPossible);
	static void	_printIntConversion(const double conversion, bool isPossible);
	static void	_printFloatConversion(const double conversion,
										 bool isPossible);
	static void	_printDoubleConversion(const double conversion,
										  bool isPossible);

	static bool		_isInf(const double number);
	static bool		_isInff(const float number);
};


#endif
