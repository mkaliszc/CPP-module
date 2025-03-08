/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:23:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 14:49:16 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal(){
	this->Animal::type = "Dog";
	std::cout << "Dog constructor\n";
}

Dog::Dog(const Dog &other) : Animal(other) {
	*this = other;
}

Dog& Dog::operator=(const Dog &other)
{
	this->Animal::type = other.type;
	return(*this);
}

void	Dog::makeSound() {
	std::cout << "ouaf ouaf\n";
}

Dog::~Dog() {
	std::cout << "Dog Destructor\n";
}