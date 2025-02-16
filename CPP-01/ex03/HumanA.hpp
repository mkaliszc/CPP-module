/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:58:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/16 19:04:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string.h>
# include "Weapon.hpp"

class HumanA
{
	private :
		std::string	name;
		Weapon& stuff;

	public :
		HumanA(const std::string& name, Weapon& stuff);
		~HumanA();
		void	attack();
};