/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:06:35 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/20 17:48:27 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <string>
# include <iostream>
# include <fstream>

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int	grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		const Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		Bureaucrat(int startingGrade);
		Bureaucrat(std::string name, int startingGrade);
		Bureaucrat(std::string name);

		void 				setGrade(int grade);
		int					getGrade() const;
		const std::string	getName() const;
		
		void	IncrementGrade();
		void	DecreamentGrade();

		void	signForm(AForm &toSign);
		
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &a);