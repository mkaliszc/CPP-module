/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/17 14:21:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	Diamond("Chiant");
	// FragTrap	Frag("Frag");
	// ScavTrap	test("Scav");
	std::cout << std::endl;

	
	// test.attack("Pedro");
	// Frag.attack("Scav");
	Diamond.attack("Chiant");
	std::cout << std::endl;

	// test.takeDamage(0);
	// Frag.takeDamage(0);
	Diamond.takeDamage(0);
	std::cout << std::endl;
	
	// test.beRepaired(5);
	// Frag.beRepaired(10);
	Diamond.beRepaired(0);
	std::cout << std::endl;

	// test.guardGate();
	// Frag.highFivesGuys();
	Diamond.whoAmI();
	std::cout << std::endl;

	return 0;
}