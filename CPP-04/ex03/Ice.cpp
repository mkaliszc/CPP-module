/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:06:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/11 19:07:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice has been created\n";
}

Ice::~Ice(){
	std::cout << "Ice didn't survive the heat\n";
}

Ice::Ice (const Ice &other) {
	this->AMateria::type = other.type;
}

Ice&	Ice::operator=(const Ice &other)
{
	this->AMateria::type = other.type;
	return (*this);
}

void	Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria	*Ice::clone() const {
	return (new Ice(*this));
}