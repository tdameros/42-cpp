#ifndef BRAIN_HPP
# define BRAIN_HPP

# define IDEAS_SIZE 100

# include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain& other);
	~Brain(void);

	Brain&	operator=(const Brain& other);

private:
	std::string	_ideas[IDEAS_SIZE];
};

#endif
