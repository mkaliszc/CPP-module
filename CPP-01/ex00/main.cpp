/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:44:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/14 19:18:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

void	randomchump(std::string name)
{
	Zombie	random;
	
	random.set_zombie_name(name);
	random.announce();
}

Zombie* NewZombie(std::string name)
{
	Zombie *new_zombie = new Zombie();
	new_zombie->set_zombie_name(name);
	return(new_zombie);
}

int	main()
{
	Zombie		*YourZombie;
	std::string name;

	std::cout << "What is the name of the Zombie ?\n";
	std::getline(std::cin, name);

	YourZombie = NewZombie(name);
	YourZombie->announce();
	delete YourZombie;

	std::cout << std::endl;
	randomchump("randomchump");
}