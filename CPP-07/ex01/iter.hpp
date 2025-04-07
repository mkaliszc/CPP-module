/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:11:34 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/03 18:42:36 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>

template<typename T, typename F>
void	iter(T *array, int len, F func)
{
	for (int i = 0; i < len; i++)
		func(array[i]);
}