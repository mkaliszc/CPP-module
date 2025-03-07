/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:23:11 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/06 16:15:50 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), GateKeeper(false)
{
	this->Name = "Default";
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "Hello from ScavTrap default constructor\n";
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name), GateKeeper(false)
{
	this->Name = Name;
	this->Hit_points = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "Hello from ScavTrap string constructor\n";
}

ScavTrap::ScavTrap(const ScavTrap &other){
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	this->Name = other.Name;
	this->Energy_points = other.Energy_points;
	this->Hit_points = other.Hit_points;
	this->Attack_damage = other.Attack_damage;
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "Goodbye from ScavTrap destructor\n";
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->Hit_points == 0)
		std::cout << this->Name << " is dead, he can't attack\n";
	else if (this->Energy_points == 0)
		std::cout << this->Name << " doesn't have any Energy_points left\n";
	else
	{
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of dammage !\n";
		if (this->Energy_points != 0)
			this->Energy_points--;
		std::cout << "ScavTrap " << this->Name << " energy left : " << this->Energy_points << std::endl;
	}
}

void	ScavTrap::guardGate(){
	this->GateKeeper = true;
	std::cout << "ScavTrap " << this->Name << " is now in gate keeper mode\n";
}