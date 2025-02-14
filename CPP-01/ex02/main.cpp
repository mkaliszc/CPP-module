/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 20:35:48 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/14 21:07:44 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string.h>

int main()
{
	std::string 	string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Adress held by string : " << &string << std::endl;
	std::cout << "Adress held by stringPTR : " << stringPTR << std::endl;
	std::cout << "Adress held by stringREF : " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "Value held by string = " << string << std::endl;
	std::cout << "Value pointed by stringPTR = " << *stringPTR << std::endl;
	std::cout << "Value pointed by stringREF = " << stringREF << std::endl;
	return (0);
}