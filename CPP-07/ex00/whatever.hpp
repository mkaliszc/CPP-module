/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:06:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/03 14:43:00 by mkaliszc         ###   ########.fr       */
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

template<typename Type>
Type	min(Type a, Type b) {
	return (b <= a) ? b : a;
}

template<typename Type>
Type	max(Type a, Type b) {
	return (b >= a) ? b : a;
}