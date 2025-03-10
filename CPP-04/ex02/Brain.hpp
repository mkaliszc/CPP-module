/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:09:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/10 14:31:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "include.h"


class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &other);
		Brain	&operator=(const Brain &other);
		~Brain();

		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index) const;
};


