/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:46:59 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/14 14:33:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <algorithm>
# include <vector>
# include <cstdlib>
# include <ctime>
# include <limits>


class Span
{
	private:
		unsigned int		_size;
		std::vector<int>	_span;

	public:
		Span();
		Span(unsigned int N);
		Span& operator=(const Span &src);
		Span(const Span &other);
		~Span();
		
		void	addNumber(int N);
		int		shortestSpan();
		int		longestSpan();

	class NoSpaceLeft : public std::exception {
		public:
			virtual const char	*what() const throw();
	};
	class TooShort : public std::exception {
		public:
			virtual const char	*what() const throw();
	};
};