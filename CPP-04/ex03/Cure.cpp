/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:25:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 16:00:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure has been created\n";
}

Cure::~Cure() {
	std::cout << "Cure didn't survive the poison\n";
}

Cure::Cure (const Cure &other) {
	this->AMateria::type = other.type;
}

Cure&	Cure::operator=(const Cure &other)
{
	this->AMateria::type = other.type;
	return (*this);
}

void	Cure::use(ICharacter &target) {
	std::cout << " * heals " << target.getName() << "'s wounds *\n";
}

AMateria	*Cure::clone() const {
	return (new Cure(*this));
}