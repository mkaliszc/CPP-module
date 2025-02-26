/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:32:52 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/26 20:07:01 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					FixedPoint;
		const static int	rawbits = 8;
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		bool operator>(const Fixed &fixed);
		bool operator<(const Fixed &fixed);
		bool operator>=(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);
		bool operator!=(const Fixed &fixed);
		Fixed operator+(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		~Fixed();
};

std::ostream &operator<<(std::ostream& out, const Fixed& value);