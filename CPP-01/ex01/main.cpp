/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:44:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/14 21:07:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie *horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].set_zombie_name(name);
	return (horde);
}

int	main()
{
	Zombie	*my_army;
	std::string name;

	std::cout << "What is the name of the Zombie ?\n";
	std::getline(std::cin, name);
	
	my_army = zombieHorde(10, name);
	for (int i = 0; i < 10; i++)
		my_army[i].announce();
	delete[] my_army;
	std::cout << std::endl;
	return (0);
}