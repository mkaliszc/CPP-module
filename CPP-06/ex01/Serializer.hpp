/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 21:14:48 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/01 21:26:24 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <string>
# include <iostream>
# include <stdint.h>

typedef struct Data
{
	std::string name;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer &src);
		Serializer	&operator=(const Serializer &src);
		~Serializer();
	
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);		
};
