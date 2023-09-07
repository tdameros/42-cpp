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

#include "iter.hpp"

template <typename T>
void	printArray(const T* array, size_t length);
void	modulo2(int& n);
void	upperChar(char& c);

int	main(void)
{
	{
		int test[3] = {1, 2, 3};

		std::cout << "Array before modulo 2" << std::endl;
		printArray(test, 3);
		iter<int>(test, 3, &modulo2);
		std::cout << "Array after modulo 2" << std::endl;
		printArray(test, 3);
	}
	{
		char test[5] = {'H', 'e', 'l', 'l', 'o'};

		std::cout << "Array before upperChar" << std::endl;
		printArray(test, 5);
		iter<char>(test, 5, &upperChar);
		std::cout << "Array after upperChar" << std::endl;
		printArray(test, 5);

	}
	return (0);
}

template <typename T>
void	printArray(const T* array, size_t length)
{
	std::cout << "[";
	for (size_t i = 0; i < length; i++)
	{
		if (i == 0)
			std::cout << array[i];
		else
			std::cout << ", " << array[i];
	}
	std::cout << "]" << std::endl;
}

void	modulo2(int& n)
{
	n = n % 2;
}

void	upperChar(char& c)
{
	c = toupper(c);
}

