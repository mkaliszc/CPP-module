/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:23:00 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/10 15:05:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Dog.hpp"

Dog::Dog() : Animal(), head(new Brain()) {
	this->Animal::type = "Dog";
	std::cout << "Dog constructor\n";
}

Dog::Dog(const Dog &other) : Animal(other), head(NULL) {
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

Brain*	Dog::getBrain() const {
	return(this->head);
}

Dog::~Dog() {
	std::cout << "Dog Destructor\n";
	delete (this->head);
}