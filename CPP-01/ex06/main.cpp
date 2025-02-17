/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:28:33 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/17 20:48:46 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

int	getLevelIndex(std::string level)
{
	std::string	valid_level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	
	for (size_t i = 0; i < 4; i++)
		if (valid_level[i] == level)
			return(i);
	return(-1);
}

void	Harl_switch(std::string level, Harl &harl)
{
	switch (getLevelIndex(level))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default :
			std::cout << "[ Probably complaining about insignificant problems ]\n";
	}
}

int main(int argc, char **argv)
{
	Harl test;

	if (argc != 2)
		std::cout << "Harl only take 1 arguments, Harl.exe cannot work\n";
	else
		Harl_switch(argv[1], test);
	return(0);
}