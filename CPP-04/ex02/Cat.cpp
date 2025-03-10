/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:27:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/10 15:05:09 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal(), head(new Brain()) {
	this->Animal::type = "Cat";
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other), head(NULL) {
	*this = other;
}

Cat& Cat::operator=(const Cat &other)
{
	this->Animal::type = other.type;
	return(*this);
}

void	Cat::makeSound(){
	std::cout << "Meowwwwwwww\n";
}

Brain*	Cat::getBrain() const {
	return(this->head);
}

Cat::~Cat() {
	std::cout << "Cat Destructor called\n";
	delete (this->head);
}