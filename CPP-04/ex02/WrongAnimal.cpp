/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:41:57 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 16:42:47 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Unknow") {
	std::cout << "WrongAnimal has been created\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	this->type = other.type;
	return(*this);
}

std::string	WrongAnimal::getType() const {
	return (this->type);
}

void	WrongAnimal::makeSound() {
	std::cout << "Some unknown WrongAnimals sound\n";
}


WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal Destructor called\n";
}