#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>

class Span
{
public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &other);
	~Span(void);

	Span& operator=(const Span& other);

	void	addNumber(int number);
	void	addMultipleNumbers(int start, int stop);
	int 	longestSpan(void);
	int 	shortestSpan(void);

private:
	unsigned int		_max_size;
	std::vector<int>	_numbers;
};

#endif
