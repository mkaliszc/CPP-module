/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/24 19:00:34 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int main()
{
	Intern	esclave;
	AForm	*test = esclave.makeForm("RobotoyRequestForm", "home");
	Bureaucrat	Xavier("Xavier", 1);

	if (test != NULL) {
		Xavier.signForm(*test);
		Xavier.executeForm(*test);
		delete test;
	}
}