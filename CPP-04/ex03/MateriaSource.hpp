/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 18:13:16 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 15:46:26 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* source[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &other);
		MateriaSource	&operator=(const MateriaSource &other);
		~MateriaSource();
		void	learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};
