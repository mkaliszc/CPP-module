/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:03 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/22 19:08:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Not enough arguments." << std::endl << "Usage: ./btc <file_name>" << std::endl;
		exit(0);
	}
	
	BitcoinExchange	test;

	test.FillMap(argv[1]);
}