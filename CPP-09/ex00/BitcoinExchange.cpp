/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/22 21:17:51 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src) {
		this->_data = src._data;
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange &src) {
	this->_data = src._data;
	return(*this);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::FillMap(std::string DataBase)
{
	std::ifstream	input(DataBase.c_str());
	std::string		date;
	std::string		value;

	if(!input.is_open())
	{
		std::cout << "here\n";
		exit(1);
	}
	std::getline(input,date);
	while (std::getline(input, date, ',') && std::getline(input, value))
			this->_data.insert(std::make_pair(date, std::atof(value.c_str())));
	input.close();
}

void	BitcoinExchange::CalculateValue(std::string infile)
{
	std::ifstream input(infile.c_str());

	// Todo : check for valid date / value and write the message, if any error occurs just write an Error message
}

bool	BitcoinExchange::ValidDate(std::string Date)
{
	// todo : check if the date exist, if yes return true
	// ? check for equation to calcul ? 
	// ! handle bixestil year
}