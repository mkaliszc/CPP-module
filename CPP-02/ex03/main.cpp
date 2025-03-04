/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 15:37:55 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/04 13:22:35 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main()
{
	Point a( 0,0 );
	Point b( 20,0 );
	Point c( 10,30 );
	Point point( 10, 15);

	if (!bsp(a, b, c, point))
		std::cout << "Point is not inside triangle" << std::endl;
	else
		std::cout << "Point is inside the triangle" << std::endl;
	Point point2(10,25);
	if (!bsp(a, b, c, point2))
		std::cout << "Point is not inside triangle" << std::endl;
	else
		std::cout << "Point is inside the triangle" << std::endl;
	Point point3(10, 30);
	if (!bsp(a, b, c, point3))
		std::cout << "Point is not inside triangle" << std::endl;
	else                                                                                                                                                                                                                                      
		std::cout << "Point is inside the triangle" << std::endl;
}