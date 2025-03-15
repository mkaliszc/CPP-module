/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:53:58 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/15 15:51:11 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AMateria.hpp"

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	std::string	name;
public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	~Character();
	
	Character &operator=(const Character &other);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};
