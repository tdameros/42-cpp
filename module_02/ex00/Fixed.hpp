#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();

	Fixed& operator=(const Fixed& other);

	int		getRawBits(void) const;
	void	setRawBits(const int raw);

private:
	int					_rawBits;
	static const int	_fractionalBits = 8;
};

#endif