/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 17:29:33 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

int main()
{
	{
		AForm *test = new ShrubberyCreationForm();
		Bureaucrat *a = new Bureaucrat(6); 
		
		try
		{
			a->signForm(*test);
			a->executeForm(*test);
		}
		catch(const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete (a);
		delete (test);
	}
	std::cout << std::endl;
	{
		AForm *test = new RobotomyRequestForm();
		Bureaucrat *a = new Bureaucrat(6); 
	
		try
		{
			a->signForm(*test);
			a->executeForm(*test);
		}
		catch(const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete (a);
		delete (test);
	}
	std::cout << std::endl;
	{
		AForm *test = new PresidentialPardonForm();
		Bureaucrat *a = new Bureaucrat(1); 
		
		try
		{
			a->signForm(*test);
			a->executeForm(*test);
		}
		catch(const std::exception &e) {
			std::cout << e.what() << std::endl;
		}
		delete (a);
		delete (test);
	}
}