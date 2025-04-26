/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:39:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/26 17:18:57 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <stack>

class RPN 
{
	private:
		std::stack<double> _value;

		RPN(const RPN &other);
		RPN&	operator=(const RPN &other);
		
	public:
		RPN();
		~RPN();

		void	calculate(std::string args);
		void	handleADD();
		void	handleTIME();
		void	handleDIVIDE();
		void	handleSUB();

	class	NotEnoughValue : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	InvalidInput : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
	class	DivideBy0 : public std::exception
	{
		public:
			virtual const char	*what() const throw();	
	};
};