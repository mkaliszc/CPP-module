/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:06:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/17 17:32:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>

template<typename Type>
void	swap(Type &a, Type &b)
{
	Type tmp = a;

	a = b;
	b = tmp;
}

/* template<typename Type>
Type	min(Type a, Type b) {
	return (b <= a) ? b : a;
}

template<typename Type>
Type	max(Type a, Type b) {
	return (b >= a) ? b : a;
} */

template <typename T>
T const &min(T const &a, T const &b) {
	return (a < b ? a : b);
}

template <typename T>
T const &max(T const &a, T const &b) {
	return (a > b ? a : b);
}