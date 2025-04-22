/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:43 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/22 21:16:02 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once 

# include <string>
# include <fstream>
# include <iostream>
# include <map>
# include <algorithm>
# include <iterator>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&	operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	FillMap(std::string DataBase); // * fill the map in private without checking

		void	CalculateValue(std::string infile); // TODO : calculate the value and validate at the same time

		bool	ValidValue(std::string Date);
		bool	ValidDate(std::string);

		std::map<std::string, float>::iterator	ClosestPreviousDate(std::string date);

};