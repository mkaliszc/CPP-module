/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:11:42 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/20 17:47:28 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string	AFormName;
		bool		Signed;
		const int	signGrade;
		const int	execGrade;
	public:
		AForm();
		AForm(std::string name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm	&operator=(const AForm &other);
		virtual ~AForm();

		std::string	getName() const;
		bool		getStatus() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void			beSigned(Bureaucrat &employee);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, AForm &tmp);
