#ifndef SPAN_HPP
# define SPAN_HPP

# include <stack>
# include <deque>

template <typename T>
class MutantStack: public std::stack<T>
{
public:

	MutantStack(void): std::stack<T>() {};
	MutantStack(const MutantStack& other): std::stack<T>(other) {};
	~MutantStack() {};

	MutantStack&	operator=(const MutantStack& other)
	{
		*this = other;
		return (*this);
	};

	typedef typename std::deque<T>::iterator			iterator;
	typedef typename std::deque<T>::reverse_iterator 	reverse_iterator;

	iterator	begin(void)
	{
		return (this->c.begin());
	}
	iterator	end(void)
	{
		return (this->c.end());
	}

	reverse_iterator	rbegin(void)
	{
		return (this->c.rbegin());
	}

	reverse_iterator	rend(void)
	{
		return (this->c.rend());
	}
};

#endif
