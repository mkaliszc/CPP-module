/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:45:51 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/12 21:24:23 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private :
		Contact Contact_list[8];
		int	count;
	public :
		PhoneBook();
		~PhoneBook();
		void	Add_Contact();
		Contact	get_contact_id(int);
		void	Display_book();
};

#endif