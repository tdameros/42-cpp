/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdameros <tdameros@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:28:00 by tdameros          #+#    #+#             */
/*   Updated: 2023/09/07 14:28:00 by tdameros         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T& a, T& b)
{
	T tmp = b;

	b = a;
	a = tmp;
}

template<typename T>
const T&	min(const T& a, const T& b)
{
	if (b <= a)
		return (b);
	return (a);
}

template<typename T>
const T&	max(const T& a, const T& b)
{
	if (b >= a)
		return (b);
	return (a);
}

#endif