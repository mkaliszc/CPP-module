/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:39:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/19 17:59:18 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

int main()
{
	try
	{
		
		Bureaucrat test("Gore", 150);
		Form		contract("test 1", 150, 150);
	
		std::cout << std::endl;
		std::cout << contract;
		test.signForm(contract);
		std::cout << std::endl;
		std::cout << contract;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what();
	}
	
}