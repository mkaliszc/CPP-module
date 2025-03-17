/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:13:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 16:31:57 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "include.h"

class Animal
{
	protected:
		std::string type;
		Animal();
		Animal(const Animal &other);
	public:
		Animal &operator=(const Animal &other);
		virtual ~Animal();

		std::string		getType() const;
		virtual void	makeSound() = 0;
};