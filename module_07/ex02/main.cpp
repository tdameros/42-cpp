/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 15:31:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/09/07 15:31:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Array.hpp"

void	printIntArray(Array<int>& array);

int main(void)
{
	Array<int> a(5);

	for (int i = 0; i < 5; i++)
		a[i] = i;
	std::cout << a.size() << std::endl;
	printIntArray(a);
	Array<int> b;
	std::cout << b.size() << std::endl;
	printIntArray(b);
	b = a;
	a[0] = 100;
	printIntArray(b);
	printIntArray(a);
	try
	{
		std::cout << a[0] << std::endl;
		std::cout << a[5] << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}

void	printIntArray(Array<int>& array)
{
	std::cout << "[";
	for (unsigned int i = 0; i < array.size(); i++)
	{
		if (i == 0)
			std::cout << array[i];
		else
			std::cout << ", " << array[i];
	}
	std::cout << "]" << std::endl;

}
