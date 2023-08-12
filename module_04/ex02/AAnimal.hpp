#ifndef AANIMAL_HPP
#define AANIMAL_HPP

# include <string>

class AAnimal
{

public:
	AAnimal(void);
	AAnimal(const std::string type);
	AAnimal(const AAnimal& other);
	virtual ~AAnimal(void);

	AAnimal&	operator=(const AAnimal& other);

	std::string	getType(void) const;

	virtual void	makeSound(void) const = 0;

protected:
	std::string	_type;
};

#endif