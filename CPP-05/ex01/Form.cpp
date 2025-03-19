/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:30:08 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/19 17:29:58 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form() : FormName("default Form"), Signed(false), signGrade(150), execGrade(150) {
	std::cout << this->FormName << " has been created\n";
}

Form::Form(std::string name, int signGrade, int execGrade) : FormName(name), Signed(false), signGrade(signGrade), execGrade(execGrade)
{
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw Form::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw Form::GradeTooHighException();
	std::cout << this->FormName << " has been created\n";
		
}

Form&	Form::operator=(const Form &other) {
	this->Signed = other.getStatus();
	return(*this);
}

Form::Form(const Form &other) : FormName(other.getName() + "/copy"), Signed(other.getStatus()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()) {
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw Form::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw Form::GradeTooHighException();
	std::cout << this;
}

Form::~Form(){
	std::cout << this->FormName << " Has been closed !\n";
}

std::string	Form::getName() const {
	return(this->FormName);
}

bool	Form::getStatus() const {
	return(this->Signed);
}

int	Form::getSignGrade() const {
	return(this->signGrade);
}

int	Form::getExecGrade() const {
	return(this->execGrade);
}

void	Form::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() <= this->getSignGrade())
		this->Signed = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw() {
	return("Grade too high !\n");
}

const char *Form::GradeTooLowException::what() const throw() {
	return("Grade too low !\n");
}

std::ostream &operator<<(std::ostream &out, Form &tmp)
{
	out
		<< "Form information :\n"
		<< "\t- Name : " << tmp.getName() << std::endl
		<< "\t- Status : " << ((tmp.getStatus() == 1) ? "true" : "false") << std::endl
		<< "\t- Required Grade to sign it : " << tmp.getSignGrade() << std::endl
		<< "\t- Required Grade to execute it : " << tmp.getExecGrade() << std::endl
		<< std::endl;
	return(out);
}