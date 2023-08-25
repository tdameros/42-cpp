/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 00:58:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/08/25 00:58:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <typeinfo>
#include <ctime>
#include <cstdlib>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int	main(void)
{
	Base*	test = generate();

	identify(NULL);
	identify(test);
	identify(*test);
	return (0);
}

Base*	generate(void)
{
	srand(std::time(0));
	int	random_number = rand() % 3;

	if (random_number == 0)
		return (new A());
	else if (random_number == 1)
		return (new B());
	else
		return (new C());
}


void	identify(Base* p)
{
	if (p == NULL)
		std::cout << "NULL pointer" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A pointer" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B pointer" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C pointer" << std::endl;
	else
		std::cout << "Unknow pointer" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "A pointer" << std::endl;
		return;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "B pointer" << std::endl;
		return;
	}
	catch (const std::bad_cast& e) {}
	try
	{
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "C pointer" << std::endl;
		return;
	}
	catch (const std::bad_cast& e) {}
	std::cout << "Unknow pointer" << std::endl;
}
