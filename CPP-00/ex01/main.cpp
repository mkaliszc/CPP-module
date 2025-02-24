/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:16:18 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/24 20:36:05 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <sstream>
#include <csignal>
#include <cstdlib>
#include <limits.h>

void	display_contact_info(PhoneBook book, int index)
{
	system("clear");
	std::string	first_name = book.get_contact_id(index).get_first_name();
	std::string	last_name = book.get_contact_id(index).get_last_name();
	std::string	nickname = book.get_contact_id(index).get_nick_name();
	std::string	phone_number = book.get_contact_id(index).get_phone_number();
	std::string	darkest_secret = book.get_contact_id(index).get_darkest_secret();

	std::cout << "First name : " << first_name << std::endl;
	std::cout << "Last name : " << last_name << std::endl;
	std::cout << "Nickname : " << nickname << std::endl;
	std::cout << "Phone number : " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}

void	Display_book_content(PhoneBook book, int index)
{
	std::string	first_name = book.get_contact_id(index).get_first_name();
	std::string	last_name = book.get_contact_id(index).get_last_name();
	std::string	nickname = book.get_contact_id(index).get_nick_name();
	std::string	space = "";

	if(first_name.size() > 10)
		first_name = first_name.substr(0, 9) + ".";
	else
	{
		for (size_t i = 0; i < (10 - first_name.size()); i++)
			space += " ";
		first_name = space + first_name;
	}
	space = "";
	if(last_name.size() > 10)
		last_name = last_name.substr(0, 9) + ".";
	else
	{
		for (size_t i = 0; i < (10 - last_name.size()); i++)
			space += " ";
		last_name = space + last_name;
	}
	space = "";
	if(nickname.size() > 10)
		nickname = nickname.substr(0, 9) + ".";
	else
	{
		for (size_t i = 0; i < (10 - nickname.size()); i++)
			space += " ";
		nickname = space + nickname;
	}
	std::cout << "         " << index + 1 << "|" << first_name << "|" << last_name << "|" << nickname << std::endl;
}

void	handle_search(PhoneBook book)
{
	std::string	input;
	system("clear");
	std::cout << "===========================================\n";
	std::cout << "     index|first name| last name|  nickname\n";
	std::cout << "===========================================\n";
	int i = 0;

	while (i < book.get_count())
	{
		Display_book_content(book, i);
		i++;
	}
	std::cout << "Type the contact index you want :" << std::endl;
	while (true)
	{
		std::getline(std::cin, input);
		if (input.empty())
		{
			std::cout << "Invalid entry"  << std::endl;
			break;
		}
		else if (input.compare("HOME") == 0)
			break;
		else if (input > "8" || input < "0")
			std::cout << "Invalid number : please put a number between 0 and " << book.get_count() << std::endl;
		else if (input.size() > 1)
			std::cout << "Invalid number : please put a number between 0 and " << book.get_count() << std::endl;
		else
		{
			std::stringstream(input) >> i;
			if (i > book.get_count())
				std::cout << "Invalid number : No contact at this index" << std::endl;
			else
			{
				display_contact_info(book, i - 1);
				break;
			}
		}
	}	
}

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
		system("clear");
		if (input.compare("ADD") == 0)
			book.Add_Contact();
		else if(input.compare("SEARCH") == 0)
			handle_search(book);
		else if (input.compare("EXIT") == 0)
			exit(0);
		else
			std::cout << "Invalid command\nlist of command :\n	- ADD : add a contact to the phone book\n	- SEARCH : search a contact by his ID\n	- EXIT : close your phonebook\n";
	}
}

