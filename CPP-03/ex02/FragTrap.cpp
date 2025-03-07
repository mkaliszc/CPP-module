/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:04:36 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/07 14:12:57 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->Name = "Default";
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "Hello from FragTrap default constructor\n";
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name)
{
	this->Name = Name;
	this->Hit_points = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "Hello from FragTrap string constructor\n";
}

FragTrap::FragTrap(const FragTrap &other){
	*this = other;
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	this->Name = other.Name;
	this->Energy_points = other.Energy_points;
	this->Hit_points = other.Hit_points;
	this->Attack_damage = other.Attack_damage;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "Goodbye from FragTrap destructor\n";
}

void	FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << this->Name << " : High fives guys !!\n";
}