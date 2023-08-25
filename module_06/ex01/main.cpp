/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 01:14:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/08/24 01:14:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Serializer.hpp"

int main(void)
{
	Data	testData = {42};
	Data	*tmpPtr = &testData;
	std::cout << tmpPtr << std::endl;
	uintptr_t	uintDataPtr = Serializer::serialize(tmpPtr);
	Data*	dataPtr = Serializer::deserialize(uintDataPtr);
	std::cout << dataPtr << std::endl;

	std::cout << dataPtr->number << std::endl;
}