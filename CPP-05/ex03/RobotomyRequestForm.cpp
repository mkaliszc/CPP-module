/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:15:07 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 17:15:53 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy Creation", 72, 45), target("home") {
	std::cout << "Robotomy Form has been created, target : " << this->target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), target(target) {
	std::cout << "Robotomy Form has been created, target : " << this->target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src.getName().append("_copy"), src.getSignGrade(), src.getExecGrade())  {
	std::cout << "Robotomy Form has been created, target : " << this->target << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	else if (this->getStatus() == false)
		throw RobotomyRequestForm::NotSigned();
	
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout << this->target << " has been robotomized successfully !\n";
	else
		std::cout << "Robotomy failed !\n";
}

const char *RobotomyRequestForm::NotSigned::what() const throw() {
	return("Error : Robotomy Form is not signed and can't be executed");
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Robotomy Form has been closed !\n";
}