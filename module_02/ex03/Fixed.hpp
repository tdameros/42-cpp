#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
public:
	Fixed();
	Fixed(const int number);
	Fixed(const float number);
	Fixed(const Fixed& other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	bool	operator<(const Fixed& f2) const;
	bool	operator>(const Fixed& f2) const;
	bool	operator<=(const Fixed& f2) const;
	bool	operator>=(const Fixed& f2) const;
	bool	operator==(const Fixed& f2) const;
	bool	operator!=(const Fixed& f2) const;

	Fixed	operator+(const Fixed& f2) const;
	Fixed	operator-(const Fixed& f2) const;
	Fixed	operator*(const Fixed& f2) const;
	Fixed	operator/(const Fixed& f2) const;

	static Fixed&		max(Fixed& f1, Fixed& f2);
	static const Fixed&	max(const Fixed& f1, const Fixed& f2);
	static Fixed&		min(Fixed &f1, Fixed &f2);
	static const Fixed& min(const Fixed& f1, const Fixed& f2);

	int		getRawBits(void) const;
	int 	getSign(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const;
	float	toFloat(void) const;

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &other);

#endif