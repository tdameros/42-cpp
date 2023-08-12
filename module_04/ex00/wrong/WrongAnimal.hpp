#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{

public:
	WrongAnimal(void);
	WrongAnimal(const std::string type);
	WrongAnimal(const WrongAnimal& other);
	~WrongAnimal(void);

	WrongAnimal&	operator=(const WrongAnimal& other);

	std::string	getType(void) const;

	void	makeSound(void) const;

protected:
	std::string	_type;

};

#endif