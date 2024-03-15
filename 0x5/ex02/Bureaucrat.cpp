/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 14:51:57 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 13:21:47 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : name("jeffy"), grade(69)
{
	std::cout << "Initiated default Bureaucrat " << name << " with grade = " << grade << std::endl;
}

Bureaucrat::Bureaucrat( std::string _name, int _grade ) : name(_name)
															  , grade(_grade)
{
	if (_grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	if( _grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Initated Bureaucrat " << name << " with grade = " << grade << std::endl;
}

Bureaucrat::Bureaucrat ( Bureaucrat const & src ) : name(src.getName())
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> grade = src.getGrade();
	return *this;
}

// getters
std::string Bureaucrat::getName() const
{
	return this -> name;
}

int Bureaucrat::getGrade() const
{
	return this -> grade;
}

// class functionalities
void Bureaucrat::incGrade(int value)
{
	if (this -> grade - value < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this -> grade -= value;
}

void Bureaucrat::decGrade(int value)
{
	if (this -> grade + value > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this -> grade += value;
}

void Bureaucrat::signForm(std::string fname, bool success )
{
	if (success)
		std::cout << this -> name << " signed " << fname << std::endl;
	else
		std::cout << this -> name << " couldn’t sign " << fname << " because their grade doesn't meet the requirements" << std::endl;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this -> name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this -> name << " could not execute " << form.getName() << " because: " << e.what() << std::endl;
	}
}

//exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "deleting Bureaucrat " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B)
{
	os << B.getName() << ", bureaucrat grade " << B.getGrade() << std::endl;
	return (os);
}
