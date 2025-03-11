/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:53:58 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/11 17:38:10 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	//materia_source
	std::string	name;
public:
	Character();
	Character(std::string name);
	Character(const Character &other);
	~Character();
	
	Character &operator=(const Character &other);
};

Character::Character()
{
}

Character::~Character()
{
}
