/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:25:37 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/17 14:33:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("Default"), Hit_points(10), Energy_points(10), Attack_damage(0){
	std::cout << "ClapTrap " << Name << " has been created\n";
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), Hit_points(10), Energy_points(10), Attack_damage(0){
	std::cout << "ClapTrap " << Name << " has been created\n";
}

ClapTrap::ClapTrap(const ClapTrap &other){
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	this->Name = other.Name;
	this->Energy_points = other.Energy_points;
	this->Hit_points = other.Hit_points;
	this->Attack_damage = other.Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << this->Name << " has been shutdown\n";
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->Hit_points == 0)
		std::cout << this->Name << " is dead, he can't attack\n";
	else if (this->Energy_points == 0)
		std::cout << this->Name << " doesn't have any Energy_points left\n";
	else
	{
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of dammage !\n";
		if (this->Energy_points != 0)
			this->Energy_points--;
		std::cout << "ClapTrap " << this->Name << " energy left : " << this->Energy_points << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this->Hit_points)
		this->Hit_points = 0;
	else
		this->Hit_points -= amount;
	std::cout << "ClapTrap " << this->Name << " taken " << amount << " of damage\n";
	if (this->Hit_points > 0)
		std::cout << "ClapTrap " << this->Name << " hp left : " << this->Hit_points << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << " is dead\n";
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->Hit_points == 0)
		std::cout << this->Name << " is dead, he can't be reapaired\n";
	else if (this->Energy_points == 0)
		std::cout << this->Name << " doesn't have any Energy_points left\n";
	else
	{
		this->Hit_points += amount;
		std::cout << "ClapTrap " << this->Name << " healed " << amount << " of health\n";
		std::cout << "ClapTrap " << this->Name << " current hp : " << this->Hit_points << std::endl;
		if (this->Energy_points != 0)
			this->Energy_points--;
		std::cout << "ClapTrap " << this->Name << " energy left : " << this->Energy_points << std::endl;
	}
}