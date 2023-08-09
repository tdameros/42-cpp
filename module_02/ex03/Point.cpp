#include "Point.hpp"
#include "Fixed.hpp"

Point::Point(void): _x(0.f), _y(0.f) {}

Point::Point(const Fixed x, const Fixed y): _x(x), _y(y) {}

Point::Point(const Point &other): _x(other._x), _y(other._y) {}

Point::~Point(void) {}

Point&	Point::operator=(const Point &other)
{
	(void) other;
	return (*this);
}

Point	Point::operator-(const Point &p) const
{
	return (Point(this->_x - p._x, this->_y - p._y));
}

Fixed	Point::calculateCrossProduct(const Point a, const Point b)
{
	return (a._x * b._y - a._y * b._x);
}

Point	Point::getVector(const Point a, const Point b)
{
	return (b - a);
}

bool	Point::isInTriangle(const Point vertexA,
							const Point vertexB,
							const Point vertexC) const
{
	int	sign;

	sign = Point::calculateCrossProduct(Point::getVector(vertexA, vertexB),
										Point::getVector(vertexA, *this)).getSign();
	if (Point::calculateCrossProduct(Point::getVector(vertexB, vertexC),
									 Point::getVector(vertexB, *this)).getSign()
									 != sign)
		return (false);
	if (Point::calculateCrossProduct(Point::getVector(vertexC, vertexA),
									 Point::getVector(vertexC, *this)).getSign()
									 != sign)
		return (false);
	return (true);
}