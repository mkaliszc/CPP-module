/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:12:46 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/19 22:25:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "constructor called\n";
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "copy constructor called\n";
	if (this != &other)
		this->value = other.value;
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

int	Fixed::getRawBits() const
{
	return(this->value);
}

Fixed::~Fixed()
{
	std::cout << "destructor called\n";
}
