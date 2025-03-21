/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:17:12 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 17:17:47 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string			target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

		void	execute(Bureaucrat const &executor) const;
		
	class NotSigned : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};