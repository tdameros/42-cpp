#include <stdexcept>
#include <string>

#include "Span.hpp"

Span::Span(void): _max_size(0), _numbers(std::vector<int>())
{

}

Span::Span(unsigned int n): _max_size(n), _numbers(std::vector<int>())
{

}

Span::Span(const Span &other)
{
	*this = other;
}

Span::~Span(void)
{

}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		this->_max_size = other._max_size;
		this->_numbers = other._numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (_numbers.size() >= _max_size)
		throw std::length_error("The span cannot contain more elements");
	_numbers.push_back(number);
}

void Span::addMultipleNumbers(int start, int stop)
{
	while (start != stop)
	{
		addNumber(start);
		start++;
	}
}

int	Span::longestSpan(void)
{
	if (_numbers.size() < 2)
		throw std::range_error("The span must contain at least 2 elements");
	std::sort(_numbers.begin(), _numbers.end());
	return (_numbers.back() - _numbers.front());
}

int	Span::shortestSpan(void)
{
	int							shortest;

	if (_numbers.size() < 2)
		throw std::range_error("The span must contain at least 2 elements");
	std::sort(_numbers.begin(), _numbers.end());
	shortest = _numbers.at(1) - _numbers.at(0);
	for (std::vector<int>::iterator it = _numbers.begin() + 1;
		 it + 1 != _numbers.end(); it++)
	{
		if (*(it + 1) - *it < shortest)
			shortest = *(it + 1) - *it;
	}
	return (shortest);
}