#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{

public:
	Point(void);
	Point(const Fixed x, const Fixed y);
	Point(const Point& other);
	~Point(void);

	Point&	operator=(const Point& other);
	Point	operator-(const Point& p) const;

	bool	isInTriangle(const Point vertexA,
						 const Point vertexB,
						 const Point vertexC) const;

	static Fixed	calculateCrossProduct(const Point a, const Point b);
	static Point	getVector(const Point a, const Point b);

private:
	const Fixed	_x;
	const Fixed	_y;
};


#endif