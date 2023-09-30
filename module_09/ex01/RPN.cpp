#include "RPN.hpp"

RPN::RPN(void) { }

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN::~RPN(void)
{

}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		_operations = other._operations;
	}
	return (*this);
}

int	RPN::calculate(const std::string& expression)
{
	if (expression.length() == 0)
		throw (ExpressionException());
	for (size_t i = 0; i < expression.length(); i++)
	{
		if (i % 2 == 0 && isdigit(expression[i]))
			_operations.push(expression[i] - '0');
		else if (i % 2 == 0 && _isOperator(expression[i]))
			_operations.push(_calculateOperator(expression[i]));
		else if (expression[i] != ' '
				 || (expression[i] == ' ' && i == expression.length() - 1))
			throw (ExpressionException());
	}
	int result = _operations.top();
	_operations.pop();
	if (!_operations.empty() || expression[expression.length() - 1] == ' ')
		throw (ExpressionException());
	return (result);
}

int	RPN::_calculateOperator(const char c_operator)
{
	int a;
	int	b;

	if (_operations.empty())
		throw (ExpressionException());
	b = _operations.top();
	_operations.pop();
	if (_operations.empty())
		throw (ExpressionException());
	a = _operations.top();
	_operations.pop();
	if (c_operator == '+')
		return (a + b);
	else if (c_operator == '-')
		return (a - b);
	else if (c_operator == '/')
	{
		if (b == 0)
			throw (std::runtime_error("Error: division by zero"));
		return (a / b);
	}
	else if (c_operator == '*')
		return (a * b);
	return (a);
}

bool	RPN::_isOperator(const char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}
