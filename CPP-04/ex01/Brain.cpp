/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:13:50 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/10 14:46:31 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain() {
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = "Random idea";
}

Brain::Brain(const Brain &other) {
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain&	Brain::operator=(const Brain &other)
{
	for (size_t i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
	return(*this);
}

void	Brain::setIdea(int index, std::string idea)
{
	if (index > 99 || index < 0)
		std::cout << "Invalid index\n";
	else
		this->ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const {
	if (index < 0 || index > 99)
		return("No idea there");
	else
		return (this->ideas[index]);
}

Brain::~Brain() {
}
