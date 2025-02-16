/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:06:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/16 17:55:42 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &type) : name(name), stuff(type)
{
}

HumanA::~HumanA()
{
	std::cout << this->name << " is dead\n";
}

void	HumanA::attack()
{
	std::cout << this->name << " attacks with their " << this->stuff.getType() << std::endl;
}