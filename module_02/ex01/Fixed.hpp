#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed &other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

	int		toInt(void) const;
	float	toFloat(void) const;

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);

#endif