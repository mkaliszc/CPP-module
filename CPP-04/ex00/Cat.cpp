/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:27:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 16:50:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cat.hpp"

Cat::Cat() : Animal() {
	this->Animal::type = "Cat";
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other){
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

Cat::~Cat() {
	std::cout << "Cat Destructor called\n";
}