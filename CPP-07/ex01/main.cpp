/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 17:11:26 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/03 18:43:07 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "iter.hpp"

void	printsize(std::string str)
{
	std::cout << str.length() << std::endl;
}

int	main()
{
	std::string	array[] = {"Hello", "world !", "coucou"};
	
	iter(array, 3, *printsize);
}