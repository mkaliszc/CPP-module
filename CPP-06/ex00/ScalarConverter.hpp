/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 17:26:20 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/04/01 15:54:43 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <cstdlib>
# include <limits.h>
# include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter	&operator=(const ScalarConverter &src);
		~ScalarConverter();
		
	public:
		static void	convert(std::string param);
		
};
