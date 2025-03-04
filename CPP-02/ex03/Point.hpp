/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:45:08 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/04 13:15:54 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Fixed.hpp"

class Point
{
	public :
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		const Fixed &getX() const;
		const Fixed &getY() const;
		~Point();
	private :
		Fixed const x;
		Fixed const y;
};

bool	bsp(Point const a, Point const b, Point const x, Point const Point);