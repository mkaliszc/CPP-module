/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:26:12 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/11 18:57:20 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AMateria.hpp"

AMateria::AMateria(){
}

AMateria::AMateria(std::string const &type) : type(type){
}

AMateria::AMateria(const AMateria &other) : type(other.type) {
}

AMateria::~AMateria(){
}

AMateria&	AMateria::operator=(const AMateria &other)
{
	this->type = other.type;
	return(*this);
}

std::string const&	AMateria::getType() const {
	return(this->type);
}

void	AMateria::use(ICharacter& target) {
	std::cout << target.getName() << " use an AMateria\n";
}