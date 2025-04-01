/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:26:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/01 18:36:29 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void	maxInfConvert() {
	std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << "+inf" << std::endl;
	std::cout << "float: " << "+inf"  << "f" << std::endl;
	std::cout << "double: " << "+inf"  << std::endl;
}

void	minInfConvert() {
	std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << "-inf" << std::endl;
	std::cout << "float: " << "-inf"  << "f" << std::endl;
	std::cout << "double: " << "-inf"  << std::endl;
}

void	nanConvert() {
	std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << "nan" << std::endl;
	std::cout << "float: " << "nan"  << "f" << std::endl;
	std::cout << "double: " << "nan"  << std::endl;
}

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
	std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << "Error" << std::endl;
	std::cout << "float: " << "Error" << std::endl;
	std::cout << "double: " << "Error"  << std::endl;
	exit (1);
}

void	convertToChar(std::string param)
{
	std::cout << "char: " << param[0] << std::endl;
	std::cout << "int: " << static_cast<int>(param[0]) << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << static_cast<float>(param[0]) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(param[0]) << std::endl;
}

void	convertToInt(std::string param)
{
	int	n = std::atoi(param.c_str());

	if (n > 32 && n < 127)
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << static_cast<float>(n) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << std::endl;
}

void	convertToFloat(std::string param)
{
	float	nf = std::atof(param.c_str());

	if (nf > 32 && nf < 127)
		std::cout << "char: " << static_cast<char>(nf) << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nf) << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << nf << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(nf) << std::endl;
}

void	convertToDouble(std::string param)
{
	double	nd = std::atof(param.c_str());

	if (nd > 32 && nd < 127)
		std::cout << "char: " << static_cast<char>(nd) << std::endl;
	else
		std::cout << "char: Non-displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(nd) << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "float: " << static_cast<float>(nd) << "f" << std::endl;
	std::cout << "double: " << nd << std::endl;
}

void	ScalarConverter::convert(std::string param)
{
	if (checkEdgeCase(param))
		return ;
	else if (param.length() == 1 && !std::isdigit(param[0])) {
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
	else if (!param.empty() && param[param.length() - 1] == 'f' && param.find('.') != std::string::npos)
	{
		bool	_isdigit = true;
		int		count = 0;
		size_t	i = 0;

		if (param[0] == '+' || param[0] == '-')
			i = 1;
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
		size_t	i = 0;

		if (param[0] == '+' || param[0] == '-')
			i = 1;
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
	else
		error();
}