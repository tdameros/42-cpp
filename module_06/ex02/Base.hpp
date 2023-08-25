#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	Base(void);
	Base(const Base &other);
	virtual	~Base(void);

	Base &operator=(const Base &other);
};

#endif
