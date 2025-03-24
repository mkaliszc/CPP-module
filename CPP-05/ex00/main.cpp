/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 15:13:49 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat test("Gore", 1);
		std::cout << test;
		test.IncrementGrade();
		std::cout << test;
		test.DecreamentGrade();
		std::cout << test;
	}
	catch (const Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what();
	}
	catch (const Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what();
	}
}