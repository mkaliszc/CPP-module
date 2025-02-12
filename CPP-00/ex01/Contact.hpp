/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 15:25:21 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/12 20:47:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private :
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
		
	public :
		Contact();
		~Contact();
		void		set_first_name(std::string);
		void		set_last_name(std::string);
		void		set_nick_name(std::string);
		void		set_phone_number(std::string);
		void		set_darkest_secret(std::string);
		std::string	get_first_name();
		std::string	get_last_name();
		std::string	get_nick_name();
		std::string	get_phone_number();
		std::string	get_darkest_secret();
		
};

#endif