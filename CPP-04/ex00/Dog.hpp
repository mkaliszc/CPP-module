/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:21:10 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/08 14:44:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &other);
		Dog &operator=(const Dog &other);
		~Dog();

		void	makeSound();
};
