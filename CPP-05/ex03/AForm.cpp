/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:30:08 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/20 17:47:41 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm() : AFormName("default AForm"), Signed(false), signGrade(150), execGrade(150) {
	std::cout << this->AFormName << " has been created\n";
}

AForm::AForm(std::string name, int signGrade, int execGrade) : AFormName(name), Signed(false), signGrade(signGrade), execGrade(execGrade)
{
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw AForm::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw AForm::GradeTooHighException();
	std::cout << this->AFormName << " has been created\n";
		
}

AForm&	AForm::operator=(const AForm &other) {
	this->Signed = other.getStatus();
	return(*this);
}

AForm::AForm(const AForm &other) : AFormName(other.getName() + "/copy"), Signed(other.getStatus()), signGrade(other.getSignGrade()), execGrade(other.getExecGrade()) {
	const int testSign = this->getSignGrade();
	const int testExec = this->getExecGrade();
	
	if (testSign > 150 || testExec > 150)
		throw AForm::GradeTooLowException();
	else if (testSign < 1 || testExec < 1)
		throw AForm::GradeTooHighException();
	std::cout << this;
}

AForm::~AForm(){
	std::cout << this->AFormName << " Has been closed !\n";
}

std::string	AForm::getName() const {
	return(this->AFormName);
}

bool	AForm::getStatus() const {
	return(this->Signed);
}

int	AForm::getSignGrade() const {
	return(this->signGrade);
}

int	AForm::getExecGrade() const {
	return(this->execGrade);
}

void	AForm::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() <= this->getSignGrade())
		this->Signed = true;
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw() {
	return("Grade too high !\n");
}

const char *AForm::GradeTooLowException::what() const throw() {
	return("Grade too low !\n");
}

std::ostream &operator<<(std::ostream &out, AForm &tmp)
{
	out
		<< "AForm inAformation :\n"
		<< "\t- Name : " << tmp.getName() << std::endl
		<< "\t- Status : " << ((tmp.getStatus() == 1) ? "true" : "false") << std::endl
		<< "\t- Required Grade to sign it : " << tmp.getSignGrade() << std::endl
		<< "\t- Required Grade to execute it : " << tmp.getExecGrade() << std::endl
		<< std::endl;
	return(out);
}