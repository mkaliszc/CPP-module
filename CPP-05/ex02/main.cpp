/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/20 19:43:16 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
	AForm *test = new ShrubberyCreationForm();
	Bureaucrat *a = new Bureaucrat(1); 
	
	try
	{
		a->signForm(*test);
		test->execute(*a);
		
	}
	catch(const std::exception &e){
		std::cout << e.what() << std::endl;
	}
}