/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 16:24:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/03 18:30:14 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Point.hpp"

Point::Point() : x(0), y (0){
}

Point::Point(const float x, const float y) : x(x), y(y){
}

Point::Point(const Point &other) : x(other.x), y(other.y){
}

Point&	Point::operator=(const Point &other){
	return (*this);
}

Point::~Point(){
}

Fixed&	Point::getX() const {
	return this->x;
}

Fixed&	Point::getY() const {
	return this->y;
}

static float my_absolute(float value){
	return (value < 0) ? -value : value;
}

static float area(const Point n1, const Point n2, const Point n3)
{
	return(my_absolute((
		(n1.getX() * (n2.getY() - n3.getY())) +
		(n2.getX() * (n3.getY() - n1.getY())) +
		(n3.getX() * (n1.getY() - n2.getY()))) / 2));
}

bool	bsp(Point const a, Point const b, Point const x, Point const Point)
{
	float main_area;
	float area1;
	float area2;
	float area3;
}