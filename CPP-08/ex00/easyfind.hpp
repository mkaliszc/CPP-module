/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:35:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/09 18:57:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

# include <algorithm>
# include <vector>
# include <iterator>
# include <iostream>

template<typename T>
typename T::iterator	easyfind(T& array, int nbr) {
	typename T::iterator	it = std::find(array.begin(), array.end(), nbr);
	if(it == array.end())
		throw std::exception();
	return (it);
}
