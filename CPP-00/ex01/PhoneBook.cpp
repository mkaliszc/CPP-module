/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:18:13 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/12 22:07:48 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PhoneBook.hpp"

PhoneBook::PhoneBook(){
	count = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::Add_Contact()
{
	Contact new_contact;
	std::string	input;


	std::cout << "Contact first name : ";
	std::getline(std::cin, input);
	new_contact.set_first_name(input);

	std::cout << "Last name : ";
	std::getline(std::cin, input);
	new_contact.set_last_name(input);

	std::cout << "Nickname : ";
	std::getline(std::cin, input);
	new_contact.set_nick_name(input);

	std::cout << "Phone number : ";
	std::getline(std::cin, input);
	new_contact.set_phone_number(input);

	std::cout << "Darkest secret ? ";
	std::getline(std::cin, input);
	new_contact.set_phone_number(input);

	if (count < 8)
		Contact_list[count++] = new_contact;
	else
	{
		std::cout << "Your personnal PhoneBook is full !\n replacing your oldest contact...\n";
		int i = 0;
		while (i < 7)
		{
			Contact_list[i] = Contact_list[i + 1];
			i++;
		}
		Contact_list[7] = new_contact;
	}
}