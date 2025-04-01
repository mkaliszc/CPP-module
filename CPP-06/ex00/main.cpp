/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 18:53:40 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/01 18:34:00 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Error: No parameter given !\nUsage: ./convert [character to convert]\n";
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}