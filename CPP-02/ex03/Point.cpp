/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:24:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/04 13:17:13 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : x(0), y (0){
}

Point::Point(const float x, const float y) : x(x), y(y){
}

Point::Point(const Point &other) : x(other.x), y(other.y){
}

Point& Point::operator=(const Point &src) {
	if (this == &src)
		return *this;
	return *this;
}

Point::~Point(){
}

const Fixed&	Point::getX() const {
	return this->x;
}

const Fixed&	Point::getY() const {
	return this->y;
}

static Fixed my_absolute(Fixed value){
	return (value < 0) ? value * -1 : value;
}

static Fixed area(const Point n1, const Point n2, const Point n3)
{
	return(my_absolute((
		(n1.getX() * (n2.getY() - n3.getY())) +
		(n2.getX() * (n3.getY() - n1.getY())) +
		(n3.getX() * (n1.getY() - n2.getY()))) / 2));
}

bool	bsp(Point const a, Point const b, Point const c, Point const Point)
{
	Fixed main_area = area(a, b, c);
	Fixed area1 = area(a, b, Point);
	Fixed area2 = area(a, Point, c);
	Fixed area3 = area(Point, b, c);

	if (area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	else if (main_area == area1 + area2 + area3)
		return true;
	return false;
}