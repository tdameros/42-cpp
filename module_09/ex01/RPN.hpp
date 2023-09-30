#ifndef RPN_HPP
# define RPN_HPP


# include <stack>
# include <string>

class RPN
{
public:
	RPN(void);
	RPN(const RPN &other);
	~RPN(void);

	RPN&	operator=(const RPN& other);

	int	calculate(const std::string& expression);

	class ExpressionException : public std::exception
	{
	public:
		const char* what() const throw() { return ("Error: invalid expression"); };
	};

private:
	std::stack<int>	_operations;

	int			_calculateOperator(const char c_operator);
	static bool	_isOperator(const char c);
};

#endif
