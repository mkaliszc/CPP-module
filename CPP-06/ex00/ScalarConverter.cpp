/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:26:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/29 18:41:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

bool	checkEdgeCase(std::string param)
{
	if (param == "-inf" || param == "-inff"){
		minInfConvert();
		return(true);
	}
	else if (param == "+inf" || param == "+inff"){
		maxInfConvert();
		return(true);
	}
	else if (param == "nan" || param == "nanf"){
		nanConvert();
		return(true);
	}	
	return(false);
}

void	error() {
	
}

void	convertToChar(std::string param)
{
	std::cout << "char: " << param[0] << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
}

void	convertToInt(std::string param)
{
	
}

void	convertToFloat(std::string param)
{
	
}

void	convertToDouble(std::string param)
{
	
}

void	ScalarConverter::convert(std::string param)
{
	if (checkEdgeCase(param))
		return ;
	else if (param.length() == 1 && !std::isdigit(param[0]))
	{
		convertToChar(param);
	}
	else if ((param[0] == '-' || param[0] == '+' || std::isdigit(param[0])) && 
			param.find('.') == std::string::npos && param.find('f') == std::string::npos)
	{
		bool	_isdigit = true;

		for (size_t i = 1; i < param.length(); i++)
		{
			if (!std::isdigit(param[i])){
				_isdigit = false;
				break ;
			}
		}
		if (_isdigit == true)
			convertToInt(param);
		else
			error();
		
	}
	else if (param.back() == 'f' && param.find('.') != std::string::npos)
	{
		bool	_isdigit = true;
		int		count = 0;
		size_t	i;

		if (std::isdigit(param[0]))
			i = 0;
		else if (param[0] == '+' || param[0] == '-')
			i = 1;
		else
			error();
		while (i < param.length() - 1)
		{
			if (!std::isdigit(param[i]) && param[i] != '.') {
				_isdigit = false;
				break ;
			}
			else if (param[i] == '.')
				count++;
			i++;
		}
		if (_isdigit && count == 1)
			convertToFloat(param);
		else
			error();
	}
	else if (param.find('.') != std::string::npos)
	{
		bool	_isdigit = true;
		int		count = 0;
		size_t	i;

		if (std::isdigit(param[0]))
			i = 0;
		else if (param[0] == '+' || param[0] == '-')
			i = 1;
		else
			error();
		while (i < param.length())
		{
			if (!std::isdigit(param[i]) && param[i] != '.') {
				_isdigit = false;
				break ;
			}
			else if (param[i] == '.')
				count++;
			i++;
		}
		if (_isdigit && count == 1)
			convertToDouble(param);
		else
			error();
	}
}