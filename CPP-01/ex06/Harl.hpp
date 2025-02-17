/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:28:47 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/17 18:31:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <string.h>

class Harl
{
	private:
		void	debug();
		void	info();
		void	warning();
		void	error();

	public:
		Harl();
		~Harl();
		void	complain(std::string level);
};
