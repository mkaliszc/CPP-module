/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:09:23 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/24 18:51:16 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

Intern::Intern() {
	std::cout << "New Intern has been recruted\n";
}

Intern::Intern(const Intern &src){
	(void)src;
}

Intern&	Intern::operator=(const Intern &src) {
	(void)src;
	return (*this);
}

Intern::~Intern() {
	std::cout << "Intern has been fired\n";
}

AForm*	Intern::makeForm(std::string FormName, std::string target)
{
	std::string	validName[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (size_t j = 0; j < 3; j++){
		if (validName[j] == FormName)
		{
			std::cout << "Intern creates " << FormName << std::endl;
			switch (j)
			{
			case 0:
				return (new ShrubberyCreationForm(target));
			case 1:
				return (new RobotomyRequestForm(target));
			case 2:
				return (new PresidentialPardonForm(target));
			}
		}
	}
	std::cout << "Intern can't create this form it doesn't exist\n";
	return(NULL);
}