/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:11:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/19 17:14:03 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string	FormName;
		bool		Signed;
		const int	signGrade;
		const int	execGrade;
	public:
		Form();
		Form(std::string name, int signGrade, int execGrade);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		std::string	getName() const;
		bool		getStatus() const;
		int	getSignGrade() const;
		int	getExecGrade() const;

		void	beSigned(Bureaucrat &employee);

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

std::ostream &operator<<(std::ostream &out, Form &tmp);
