/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:59:09 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 15:14:48 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string			target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const &executor) const;
		
	class NotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};