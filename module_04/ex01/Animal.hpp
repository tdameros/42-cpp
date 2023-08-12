#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>

class Animal
{

public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal& other);
	virtual ~Animal(void);

	Animal&	operator=(const Animal& other);

	std::string	getType(void) const;

	virtual void	makeSound(void) const;

protected:
	std::string	_type;
};

#endif