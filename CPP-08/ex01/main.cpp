/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:45:04 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/26 17:25:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

int	main()
{
	int		value = 0;
	int		size = 10;

	try
	{
		Span	test(size);

		srand(time(NULL));
		for (int i = 0; i < size; i++) {
			value = rand() % size;
			test.addNumber(value);
			std::cout << value << " ";
		}
		std::cout << std::endl << "Shortest Span : " << test.shortestSpan() << std::endl;
		std::cout << std::endl << "Longest Span : " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	
}
