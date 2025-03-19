/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaliszc <mkaliszc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:29:56 by mkaliszc          #+#    #+#             */
/*   Updated: 2025/03/19 17:59:52 by mkaliszc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"
# include "Form.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150) {
	std::cout
		<< "Everyone say welcome to "
		<< this->name
		<< " grade number : "
		<< this->grade
		<< std::endl;
}

Bureaucrat::Bureaucrat(int startingGrade) : name("Default") {
	try {
		this->setGrade(startingGrade);
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Grade has been set to the highest grade possible (1)\n";
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Grade has been set to the lowest grade possible (150)\n";
	}
	
	std::cout
		<< "Everyone say welcome to "
		<< this->name
		<< " grade number : "
		<< this->grade
		<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int startingGrade) : name(name) {
	try {
		this->setGrade(startingGrade);
	}
	catch(const Bureaucrat::GradeTooHighException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Grade has been set to the highest grade possible (1)\n";
	}
	catch(const Bureaucrat::GradeTooLowException& e) {
		std::cerr << e.what() << std::endl;
		std::cerr << "Grade has been set to the lowest grade possible (150)\n";
	}
	std::cout 
		<< "Everyone say welcome to "
		<< this->name << " grade number : "
		<< this->grade
		<< std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : name(name) , grade(150) {
	std::cout 
		<< "Everyone say welcome to "
		<< this->name
		<< " grade number : "
		<< this->grade
		<< std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name + "/copy"), grade(other.grade) {
	std::cout 
		<< "Everyone say welcome to "
		<< this->name
		<< " grade number : " 
		<< this->grade
		<< std::endl;
}

const Bureaucrat&	Bureaucrat::operator=(const Bureaucrat &other)
{
	this->grade = other.getGrade();
	this->name = other.getName();
	return(*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout 
		<< "Bureaucrat grade : "
		<< this->grade
		<< " called "
		<< this->name
		<< " has been fired.\n"; 
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return("Grade too high to be incremmented or set !\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return("Grade too low !\n");
}

void	Bureaucrat::IncrementGrade()
{
	this->setGrade(this->grade - 1);
	std::cout
		<< "Bureaucrat "
		<< this->name
		<< " has been promoted to the next grade, actual grade is : "
		<< this->grade
		<< std::endl;
}

void	Bureaucrat::DecreamentGrade()
{
	this->setGrade(this->grade + 1);
	std::cout
		<< "Bureaucrat "
		<< this->name
		<< " has been deranked to the previous grade, actual grade is : "
		<< this->grade
		<< std::endl;
}

const std::string	Bureaucrat::getName() const{
	return(this->name);
}

int	Bureaucrat::getGrade() const{
	return(this->grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if(grade > 150)
	{
		this->grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else if (grade < 1)
	{
		this->grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->grade = grade;
}

void	Bureaucrat::signForm(Form &toSign)
{
	try {
		toSign.beSigned(*this);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout
			<< "Bureaucrat "
			<< this->name
			<< " couldn't sign "
			<< toSign.getName()
			<< " because : "
			<< e.what();
	}
}

std::ostream	&operator<<(std::ostream &out, Bureaucrat &a) {
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << ".\n";
	return(out);
}