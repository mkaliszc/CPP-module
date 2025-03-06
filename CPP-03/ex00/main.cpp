/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:44:14 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/05 15:43:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("test1");
	clapTrap.attack("OTHER ONE");
	clapTrap.takeDamage(5);
	clapTrap.takeDamage(5);

	clapTrap.beRepaired(5);
	return 0;
}