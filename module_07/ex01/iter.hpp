/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:44:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/09/07 14:44:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template<typename T>
void	iter(T* array, size_t length, void (*func)(T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

template<typename T>
void	iter(const T* array, size_t length, void (*func)(const T&))
{
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif