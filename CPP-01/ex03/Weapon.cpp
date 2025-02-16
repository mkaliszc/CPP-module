/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:47:44 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/16 19:06:40 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type) : type(type)
{
}

Weapon::~Weapon()
{
	std::cout << this->type << " has been destroyed\n";
}

void	Weapon::setType(std::string str)
{
	this->type = str;
}

const std::string& Weapon::getType()
{
	return(this->type);
}