/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:12:46 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/03 15:19:08 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->FixedPoint = 0;
}

Fixed::Fixed(const int value)
{
	this->FixedPoint = value << this->rawbits;
}

Fixed::Fixed(const float value)
{
	this->FixedPoint = roundf(value * (1 << this->rawbits));
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->FixedPoint = other.FixedPoint;
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->FixedPoint = raw;
}

int	Fixed::getRawBits() const
{
	return(this->FixedPoint);
}

Fixed::~Fixed()
{
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

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (!(*this != fixed));
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	return (this->toFloat() +  fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}

Fixed&	Fixed::operator++()
{
	this->FixedPoint++;
	return(*this);
}

Fixed&	Fixed::operator--()
{
	this->FixedPoint--;
	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	operator++();
	return(tmp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	operator--();
	return(tmp);
}

const Fixed&	Fixed::min(const Fixed &value1, const Fixed	&value2)
{
	return (value1 < value2) ? value1 : value2;
}

Fixed&	Fixed::min(Fixed &value1, Fixed &value2)
{
	return (value1 < value2) ? value1 : value2;
}

const Fixed&	Fixed::max(const Fixed &value1, const Fixed	&value2)
{
	return (value1 > value2) ? value1 : value2;
}

Fixed&	Fixed::max(Fixed &value1, Fixed &value2)
{
	return (value1 > value2) ? value1 : value2;
}