/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:58:40 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/16 19:12:28 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string.h>
# include "Weapon.hpp"

class HumanB
{
	private :
		std::string	name;
		Weapon* stuff;

	public :
		HumanB(const std::string& name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon& weapon);
};