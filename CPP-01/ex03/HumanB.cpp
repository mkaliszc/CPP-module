/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:45:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/16 19:14:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name)
{
}

HumanB::~HumanB()
{
	std::cout << this->name << " is dead\n";
}

void	HumanB::attack()
{
	std::cout << this->name << " attacks with their " << stuff->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->stuff = &weapon;
}