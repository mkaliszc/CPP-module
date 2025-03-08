/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:43:37 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 16:50:39 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	this->WrongAnimal::type = "WrongCat";
	std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other){
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	this->WrongAnimal::type = other.type;
	return(*this);
}

void	WrongCat::makeSound(){
	std::cout << "Wrong Meowwwwwwww\n";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat Destructor called\n";
}