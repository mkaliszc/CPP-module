/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:18:01 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 17:25:09 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default Presidential Pardon form Creation", 25, 5), target("home") {
	std::cout << "Presidential Pardon Form has been created, target : " << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), target(target) {
	std::cout << "Presidential Pardon Form has been created, target : " << this->target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName().append("_copy"), src.getSignGrade(), src.getExecGrade())  {
	std::cout << "Presidential Pardon Form has been created, target : " << this->target << std::endl;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (this->getStatus() == false)
		throw PresidentialPardonForm::NotSigned();
	else
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox.\n";
}

const char *PresidentialPardonForm::NotSigned::what() const throw() {
	return("Error : Presidential Pardon Form is not signed and can't be executed");
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Presidential Pardon Form has been closed !\n";
}