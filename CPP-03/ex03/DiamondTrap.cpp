/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:40:18 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/17 14:35:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
	this->Name = "Default";
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
	this->ClapTrap::Name = this->Name + "_clap_name";
	std::cout
		<< "Hello World from DiamondTrap "
		<< this->Name
		<< std::endl;
}

DiamondTrap::DiamondTrap(std::string Name) : ClapTrap(Name), FragTrap(Name), ScavTrap(Name)
{
	this->Name = Name;
	this->Hit_points = FragTrap::Hit_points;
	this->Energy_points = ScavTrap::Energy_points;
	this->Attack_damage = FragTrap::Attack_damage;
	this->ClapTrap::Name = this->Name + "_clap_name";
	std::cout
		<< "Hello World from DiamondTrap "
		<< this->Name
		<< std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other){
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap &other)
{
	this->Name = other.Name;
	this->Hit_points = other.Hit_points;
	this->Energy_points = other.Energy_points;
	this->Attack_damage = other.Attack_damage;
	this->ClapTrap::Name = other.ClapTrap::Name;
	return (*this);
}

DiamondTrap::~DiamondTrap(){
	std::cout << "Goodbye from DiamondTrap " << this->Name << " !\n";
}

void	DiamondTrap::whoAmI(){
	std::cout << "I am DiamondTrap " << this->Name << " my Clap name is " << this->ClapTrap::Name << std::endl;
}