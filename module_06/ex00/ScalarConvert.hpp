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

	static void	convert(std::string& literal);

private:
	static void	_printCharConversion(double conversion);
	bool		_isInf()
};


#endif
