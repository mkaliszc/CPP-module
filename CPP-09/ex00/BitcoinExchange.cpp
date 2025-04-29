/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:09:27 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/28 17:04:55 by mkaliszc         ###   ########.fr       */
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
			this->_data.insert(std::pair<std::string, float>(date, std::atof(value.c_str())));
	input.close();
}

bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool	ValidDate(std::string &buffer)
{
	if (buffer.length() != 11)
		return (false);
	else if (buffer[4] != '-' || buffer[7] != '-')
		return (false);
	else if (buffer[10] != ' ')
		return (false);
	
    for (size_t i = 0; i < buffer.size() - 1; ++i)
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
		return (false);

	return (true);
}

bool	ValidValue(std::string buffer)
{
	bool	pointFound = false;
	for (size_t i = 1; i < buffer.size(); i++)
	{
		if (buffer[i] == '.' && pointFound == false)
			pointFound = true;
		else if (!std::isdigit(buffer[i]))
			return(false);
	}
	double	nbr = std::atof(buffer.substr(1, buffer.size()).c_str());

	if (nbr > 1000 || nbr < 0)
		return (false);
	return (true);
}

std::map<std::string, float>::iterator	BitcoinExchange::findDateInMap(std::string date)
{
	std::map<std::string, float>::iterator test = _data.lower_bound(date);

	if (test != _data.end() && test->first == date)
		return (test);
	else if (test == _data.begin())
		return (_data.end());
	return(test--);
}

void	BitcoinExchange::CalculateValue(std::string infile)
{
	std::ifstream input(infile.c_str());
	std::string	Line;

	if (!input.is_open())
		exit(1);
	std::getline(input, Line);
	while (std::getline(input, Line))
	{
		if (Line.empty())
		{
			std::cout << "Error: bad input => empty line" << std::endl;
			continue;
		}

		std::istringstream iss(Line);
		std::string Date, Value;

		if (!std::getline(iss, Date, '|') || !std::getline(iss, Value))
		{
			std::cout << "Error: bad input => " << Line << std::endl;
			continue;
		}
		if(!ValidDate(Date))
			std::cout << "Error: bad input => " << Date << std::endl;
		else if (!ValidValue(Value))
			std::cout << "Error: invalid value" << std::endl;
		else
		{
			std::map<std::string, float>::iterator it = findDateInMap(Date);
			
			if (it == _data.end() && Date != it->first)
				std::cout << "Error: date not found in data base." << std::endl;
			else
				std::cout << Date << " => " << Value.substr(1, Value.size()) << " = " << std::atof(Value.substr(1, Value.size()).c_str()) * it->second << std::endl;
		}
	}
}