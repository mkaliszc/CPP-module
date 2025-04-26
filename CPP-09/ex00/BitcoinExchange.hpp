/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:43 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/24 18:37:37 by mkaliszc         ###   ########.fr       */
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
		std::map<std::string, float> _data;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange&	operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	FillMap(std::string DataBase);

		void	CalculateValue(std::string infile);

		std::map<std::string, float>::iterator	findDateInMap(std::string date);

};