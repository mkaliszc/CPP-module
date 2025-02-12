/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:16:18 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/12 21:56:18 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int	main()
{
	PhoneBook book = PhoneBook();
	std::string	input;

	system("clear");
	while(true)
	{
		std::cout << "Welcome to your own phonebook !\n";
		std::cout << "What do you want to do ?\n";
		if (!getline(std::cin, input))
		{
			std::cout << "Invalid entry, closing the PhoneBook...\n";
			exit(1);
		}
		if (input.compare("ADD") == 0)
			book.Add_Contact();
	}
}

