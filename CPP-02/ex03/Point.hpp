/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:45:08 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/03 18:28:17 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Class.h"

class Point
{
	public :
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point &operator=(const Point &other);
		Fixed &getX() const;
		Fixed &getY() const;
		~Point();
	private :
		const Fixed x;
		const Fixed y;
};

bool	bsp(Point const a, Point const b, Point const x, Point const Point);