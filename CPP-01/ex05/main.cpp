/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:28:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/17 19:41:13 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int main()
{
	Harl test;
	std::string level;

	std::cout << "Wich level do you want to try ?\n";
	std::getline(std::cin, level);
	test.complain(level);
	return(0);
}