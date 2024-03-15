/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:04:56 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 14:08:20 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm( void ) : name("jeffyAForm"), is_signed(false), sign_grade(69), exec_grade(69)
{
	std::cout << "Initated default AForm " << name << " with sign grade = " << sign_grade << " and an exec grade is " << exec_grade << std::endl;
}

AForm::AForm( std::string _name, int _sign_grade, int _exec_grade ) : name(_name), is_signed(false), sign_grade(_sign_grade), exec_grade(_exec_grade)
{
	if (_sign_grade < HIGHEST_GRADE || _exec_grade < HIGHEST_GRADE)
		throw AForm::GradeTooHighException();
	if( _sign_grade > LOWEST_GRADE || _exec_grade > LOWEST_GRADE)
		throw AForm::GradeTooLowException();
	std::cout << "Initated AForm " << name << " with sign_grade = " << sign_grade << " and exec grade = " << _exec_grade << std::endl;
}

AForm::AForm ( AForm const & src ) : sign_grade(src.getSignGrade()), exec_grade(src.getExecGrade())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

AForm & AForm::operator=( AForm const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> is_signed = src.getIsSigned();
	return *this;
}

// getters
const std::string AForm::getName() const
{
	return this -> name;
}

bool AForm::getIsSigned() const
{
	return this -> is_signed;
}

int AForm::getSignGrade() const
{
	return this -> sign_grade;
}

int AForm::getExecGrade() const
{
	return this -> exec_grade;
}

// class functionalities
void AForm::beSigned(Bureaucrat &b)
{
	bool condition = b.getGrade() <= this -> getSignGrade();
	if (condition)
		this -> is_signed = true;
	b.signForm(this -> name, condition);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (this -> is_signed == false)
		throw Form_Not_Signed();
	if (executor.getGrade() > this -> exec_grade)
		throw Cannot_Exec_Action();

	this -> do_action();
}

//exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

const char *AForm::Cannot_Exec_Action::what() const throw()
{
	return "Bureaucrat grade too low!";
}

const char *AForm::Form_Not_Signed::what() const throw()
{
	return "Form is not signed!";
}

AForm::~AForm( void )
{
	std::cout << "deleting AForm " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& F)
{
	os << F.getName() << ", IsSigned = " << F.getIsSigned() << ", sign grade = " << F.getSignGrade() << ", exec grade = " << F.getSignGrade() << std::endl;
	return (os);
}
