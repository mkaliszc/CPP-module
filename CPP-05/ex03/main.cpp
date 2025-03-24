/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/24 18:48:15 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int main()
{
	Intern	esclave;
	AForm	*test = esclave.makeForm("RobotomyRequestForm", "home");
	Bureaucrat	Xavier("Xavier", 1);

	Xavier.signForm(*test);
	Xavier.executeForm(*test);

	delete test;
}