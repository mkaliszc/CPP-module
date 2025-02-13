/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 18:18:25 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/02/13 18:54:25 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){
}

Contact::~Contact(){
}

void	Contact::set_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::set_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::set_nick_name(std::string str)
{
	this->nickname = str;
}

void	Contact::set_phone_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::set_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

std::string	Contact::get_first_name()
{
	return this->first_name;
}

std::string	Contact::get_last_name()
{
	return this->last_name;
}

std::string	Contact::get_nick_name()
{
	return this->nickname;
}

std::string	Contact::get_phone_number()
{
	return this->phone_number;
}

std::string	Contact::get_darkest_secret()
{
	return this->darkest_secret;
}