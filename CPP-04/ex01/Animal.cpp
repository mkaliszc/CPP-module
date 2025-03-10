/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:15:56 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 14:57:37 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Animal.hpp"

Animal::Animal() : type("Unknow") {
	std::cout << "Animal has been created\n";
}

Animal::Animal(const Animal &other) {
	*this = other;
}

Animal& Animal::operator=(const Animal &other)
{
	this->type = other.type;
	return(*this);
}

std::string	Animal::getType() const {
	return (this->type);
}

void	Animal::makeSound(){
	std::cout << "Some unknown animals sound\n";
}


Animal::~Animal() {
	std::cout << "Animal Destructor called\n";
}