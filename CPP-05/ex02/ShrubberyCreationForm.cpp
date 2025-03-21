/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:09:32 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/21 14:10:59 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default Shrubbery Creation", 145, 137), target("home") {
	std::cout << "Shrubbery Form has been created, target : " << this->target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137), target(target) {
	std::cout << "Shrubbery Form has been created, target : " << this->target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName().append("_copy"), src.getSignGrade(), src.getExecGrade())  {
	std::cout << "Shrubbery Form has been created, target : " << this->target << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getExecGrade() < executor.getGrade())
		throw AForm::GradeTooLowException();
	if (!this->getStatus())
		throw ShrubberyCreationForm::NotSigned();
	std::ofstream output((this->target + "_shrubbery").c_str());
	output <<
	"         v" << std::endl <<
	"        >X<" << std::endl <<
	"         A" << std::endl <<
	"        d$b" << std::endl <<
	"      .d\\$$b." << std::endl <<
	"    .d$i$$\\$$b." << std::endl <<
	"       d$$@b" << std::endl <<
	"      d\\$$$ib" << std::endl <<
	"    .d$$$\\$$$b" << std::endl <<
	"  .d$$@$$$$\\$$ib." << std::endl <<
	"      d$$i$$b" << std::endl <<
	"     d\\$$$$@$b" << std::endl <<
	"  .d$@$$\\$$$$$@b." << std::endl <<
	".d$$$$i$$$\\$$$$$$b." << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	std::endl;
	output.close();
}

const char *ShrubberyCreationForm::NotSigned::what() const throw() {
	return("Error : Shrubbery Form is not signed and can't be executed");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Shrubbery Form has been closed !\n";
}