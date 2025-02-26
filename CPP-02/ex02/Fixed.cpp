/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:12:46 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/26 20:08:22 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Constructor called\n";
	this->FixedPoint = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int Constructor called\n";
	this->FixedPoint = value << this->rawbits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Int Constructor called\n";
	this->FixedPoint = roundf(value * (1 << this->rawbits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy asignement constructor called\n";
	if (this != &other)
		this->FixedPoint = other.FixedPoint;
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->FixedPoint = raw;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return(this->FixedPoint);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::toInt() const
{
	return(this->FixedPoint >> this->rawbits);
}

float	Fixed::toFloat() const
{
	return (float)(this->FixedPoint) / (1 << this->rawbits);
}

std::ostream &operator<<(std::ostream& out, const Fixed& value)
{
	out << value.toFloat();
	return (out);
}

bool	Fixed::operator!=(const Fixed &fixed)
{
	return (this->toFloat() != fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed)
{
	return (!(*this != fixed));
}

bool	Fixed::operator>=(const Fixed &fixed)
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed)
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>(const Fixed &fixed)
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed)
{
	return (this->toFloat() < fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed)
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator+(const Fixed &fixed)
{
	return (this->toFloat() +  fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed)
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed)
{
	return (this->toFloat() / fixed.toFloat());
}
