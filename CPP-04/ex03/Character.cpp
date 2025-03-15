/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:02:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 16:25:08 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Character.hpp"

Character::Character()
{
	this->name = "Default";
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Default character constructor called\n\n";
}

Character::Character(const Character &other)
{
	this->name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &other)
{
	this->name = other.name;
	for (size_t i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete inventory[i];
		if (other.inventory[i])
			this->inventory[i] = other.inventory[i]->clone();
		else
			this->inventory[i] = NULL; 
	}
	return(*this);
}

Character::Character(std::string name) : name(name)
{
	for (size_t i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << this->name << " character constructor called\n\n";
}

Character::~Character()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
	std::cout << "Character " << this->name << " has been destroyed and his inventory has been cleaned.\n";
}

std::string const& Character::getName() const {
	return(this->name);
}

void	Character::equip(AMateria *m)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (!this->inventory[i])
		{
			inventory[i] = m;
			std::cout << "AMateria : " << m->getType() << " equipped\n\n";
			return ;
		}
	}
	std::cout << "AMateria : " << m->getType() << " can't be equipped, inventory is full\n";
	delete m;
	return;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index to unequip ! Choose an index between 0 and 3.\n";
		return ;
	}
	if (this->inventory[idx])
		this->inventory[idx] = NULL;
	else
		std::cout << "No materia equiped at index : " << idx << std::endl; 
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index to unequip ! Choose an index between 0 and 3.\n";
		return ;
	}
	else if (this->inventory[idx])
	{
		std::cout << "Character / " << this->name;
		this->inventory[idx]->use(target);
		return ;
	}
	std::cout << "No materia equiped at index : " << idx << std::endl;
}