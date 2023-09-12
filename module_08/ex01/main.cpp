/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 13:33:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/09/07 13:33:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Span.hpp"

int	main(void)
{
	{
		Span testSpan(10);

		testSpan.addNumber(5);
		testSpan.addNumber(-11);
		testSpan.addNumber(-100);

		std::cout << testSpan.longestSpan() << std::endl;
		std::cout << testSpan.shortestSpan() << std::endl;
	}
	{
		Span testSpan(2);

		try
		{
			std::cout << testSpan.longestSpan() << std::endl;
		}
		catch (std::range_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		testSpan.addNumber(0);
		testSpan.addNumber(-11);
		try
		{
			testSpan.addNumber(42);
		}
		catch (std::length_error &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << testSpan.longestSpan() << std::endl;
		std::cout << testSpan.shortestSpan() << std::endl;
	}
	{
		Span testSpan(11000);

		testSpan.addMultipleNumbers(10000, 20000);
		testSpan.addNumber(9);
		testSpan.addNumber(1000);
		std::cout << testSpan.longestSpan() << std::endl;
		std::cout << testSpan.shortestSpan() << std::endl;
	}
	return (0);
}
