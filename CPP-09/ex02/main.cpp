/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:26:30 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/05/01 16:06:07 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cout << "Error: Not enough arguments, usage : ./PmergeMe <nb> <nb> <nb>..." << std::endl;
		return (1);
	}
	PmergeMe	sorter;

	sorter.parsing(argv);
	sorter.vecSort();
}