#include "Base.hpp"

Base::Base(void)
{

}

Base::Base(const Base &other)
{
	*this = other;
}

Base::~Base(void)
{

}

Base &Base::operator=(const Base &other)
{
	if (this != &other)
	{

	}
	return (*this);
}