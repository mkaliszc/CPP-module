/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:39:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/17 20:37:16 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
	std::cout << "Harl has been shut down\n";
}

void	Harl::complain(std::string level)
{
	std::string	valid_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	void (Harl::*lvl_functions[])() =
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	for (int i = 0; i < 4; i++)
	{
		if(level == valid_level[i])
		{
			(this->*lvl_functions[i])();
			return ;
		}
	}
	std::cout << "Error: Unknow level\n";
}


void	Harl::debug()
{
	std::cout << "DEBUG -> I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void	Harl::info()
{
	std::cout << "INFO -> I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more !\n";
}

void	Harl::warning()
{
	std::cout << "WARNING -> I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void	Harl::error()
{
	std::cout << "ERROR -> This is unacceptable! I want to speak to the manager now.\n";
}