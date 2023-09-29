#ifndef MUTTANTSTACK_HPP
# define MUTTANTSTACK_HPP

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

	typedef typename std::deque<T>::iterator				iterator;
	typedef typename std::deque<T>::reverse_iterator 		reverse_iterator;
	typedef typename std::deque<T>::const_iterator			const_iterator;
	typedef typename std::deque<T>::const_reverse_iterator	const_reverse_iterator;

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

	const_iterator	cbegin(void)
	{
		return (this->c.begin());
	}

	const_iterator	cend(void)
	{
		return (this->c.end());
	}

	const_reverse_iterator	crbegin(void)
	{
		return (this->c.rbegin());
	}

	const_reverse_iterator	crend(void)
	{
		return (this->c.rend());
	}
};

#endif
