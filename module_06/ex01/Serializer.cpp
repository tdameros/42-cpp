#include <stdint.h>

#include "Serializer.hpp"

Serializer::Serializer(void)
{

}

Serializer::Serializer(const Serializer& other)
{
	*this = other;
}

Serializer::~Serializer(void)
{

}

Serializer &Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{

	}
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}