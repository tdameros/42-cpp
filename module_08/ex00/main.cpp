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
#include <vector>
#include <list>

#include "easyfind.hpp"

int	main(void)
{
	{
		std::vector<int> container;
		for (int i = 5; i < 15; i++)
			container.push_back(i);
		std::cout << *easytofind(container, 9) << std::endl;
		std::cout << std::boolalpha
		<< (easytofind(container, 20) == container.end()) << std::endl;
	}
	{
		std::list<int> container;
		for (int i = 50; i < 100; i++)
			container.push_back(i);
		std::cout << *easytofind(container, 65) << std::endl;
		std::cout << std::boolalpha
		<< (easytofind(container, 10000) == container.end()) << std::endl;
	}
	return (0);
}
