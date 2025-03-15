/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:17:52 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 16:25:37 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++)
		this->source[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (this->source[i])
			delete source[i];
		if (other.source[i])
			this->source[i] = other.source[i]->clone();
		else
			this->source[i] = NULL;	
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &other)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (this->source[i])
			delete source[i];
		if (other.source[i])
			this->source[i] = other.source[i]->clone();
		else
			this->source[i] = NULL;	
	}
	return(*this);
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->source[i])
		{
			delete this->source[i];
			this->source[i] = NULL;
		}
	}
}

void	MateriaSource::learnMateria(AMateria *new_materia)
{
	if (!new_materia)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if (!source[i])
		{
			source[i] = new_materia;
			return ;
		}
	}
	std::cout << "Canno't learn Materia : " << new_materia->getType() << " no space left in MateriaSource\n";
	delete new_materia;
	return ;
}

AMateria*	MateriaSource::createMateria(std::string const &type)
{
	for (size_t i = 0; i < 4; i++)
		if (source[i] && source[i]->getType() == type)
			return source[i]->clone();
	std::cout << "Type : " << type << " not found in MateriaSource !\n";
	return (NULL);
}