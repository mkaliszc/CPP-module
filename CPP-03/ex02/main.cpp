/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/07 14:12:20 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

int main()
{
	FragTrap	Frag("Frag");
	ScavTrap	test("Scav");
	ClapTrap	Pedro("Clap");
	std::cout << std::endl;

	
	Pedro.attack("Scav");
	test.attack("Pedro");
	Frag.attack("Scav");
	std::cout << std::endl;

	test.takeDamage(0);
	Pedro.takeDamage(20);
	Frag.takeDamage(0);
	std::cout << std::endl;
	
	test.beRepaired(5);
	Pedro.beRepaired(5);
	Frag.beRepaired(10);
	std::cout << std::endl;

	test.guardGate();
	Frag.highFivesGuys();
	std::cout << std::endl;

	return 0;
}