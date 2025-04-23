/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/23 20:07:00 by mkaliszc         ###   ########.fr       */
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
		exit(1);
	std::getline(input,date);
	while (std::getline(input, date, ',') && std::getline(input, value))
			this->_data.insert(std::make_pair(date, std::atof(value.c_str())));
	input.close();
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	ValidDate(std::string buffer)
{
	if (buffer.length() != 11)
		return (false);
	else if (buffer[4] != '-' || buffer[7] != '-')
		return (false);
	else if (buffer[10] != ' ')
		return (false);
	
    for (int i = 0; i < buffer.size(); ++i)
	{
        if (i == 4 || i == 7) 
			continue;
        else if (!std::isdigit(buffer[i])) 
			return false;
    }
	
	buffer.erase(buffer.size() - 1);
	
	int	year = std::atoi(buffer.substr(0, 3).c_str());
	int	month = std::atoi(buffer.substr(5, 6).c_str());
	int	day = std::atoi(buffer.substr(8, 9).c_str());
	
	if (month > 12 || month < 1 || year < 0)
		return (false);

    int daysInMonth[] = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (day > daysInMonth[month - 1])
        return false;
	
}

bool	ValidValue(std::string buffer)
{
	for (size_t i = 1; i < buffer.size(); i++)
	{
		/* code */
	}
	
}

void	BitcoinExchange::CalculateValue(std::string infile)
{
	std::ifstream input(infile.c_str());
	std::string	bufferDate;
	std::string bufferValue;

	if (!input.is_open())
		exit(1);
	std::getline(input, bufferDate);
	while (std::getline(input, bufferDate, '|') && std::getline(input, bufferValue))
	{
		if(!ValidDate(bufferDate))
			std::cout << "Error: bad input => " << bufferDate << std::endl;
		else if (!ValidValue(bufferDate))
		{
			// ! error	
		}
		else
		{
			// * find date in map and calcul
		}
	}
	
	// Todo : check for valid date / value and write the message, if any error occurs just write an Error message
}