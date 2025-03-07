/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 16:05:44 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/06 15:39:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	private:
		bool	GateKeeper;

	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();
		
		void	attack(const std::string &target);
		void	guardGate();
};

