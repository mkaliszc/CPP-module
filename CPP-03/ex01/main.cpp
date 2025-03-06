/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/06 16:01:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ScavTrap	test("test");
	ClapTrap	Pedro("Pedro");
	std::cout << std::endl;

	
	Pedro.attack("test");
	test.attack("Pedro");
	std::cout << std::endl;

	test.takeDamage(0);
	Pedro.takeDamage(20);
	std::cout << std::endl;
	
	test.beRepaired(5);
	Pedro.beRepaired(5);
	std::cout << std::endl;

	return 0;
}