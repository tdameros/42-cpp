#ifndef ANIMAL_HPP
#define ANIMAL_HPP

# include <string>

class Animal
{

public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal& other);
	~Animal(void);

	Animal& operator=(const Animal& other);

protected:
	std::string	_type;

};


#endif