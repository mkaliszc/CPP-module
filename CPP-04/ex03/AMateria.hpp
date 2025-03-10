/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:44:39 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/10 18:25:55 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <string>

class AMateria
{
	protected:
		std::string const type;
	public:
		AMateria();
		AMateria(std::string const & type);
		
		AMateria(const AMateria &other);
		AMateria	&operator=(const AMateria &other);
		
		~AMateria();
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};