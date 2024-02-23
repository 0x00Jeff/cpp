/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:04:56 by afatimi           #+#    #+#             */
/*   Updated: 2024/02/23 18:13:19 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form( void ) : name("jeffyForm"), is_signed(false), sign_grade(69), exec_grade(69)
{
	std::cout << "Initated default Form " << name << " with sign grade = " << sign_grade << " and an exec grade is " << exec_grade << std::endl;
}

Form::Form( std::string _name, int _sign_grade, int _exec_grade ) : name(_name), is_signed(false), sign_grade(_sign_grade), exec_grade(_exec_grade)
{
	if (_sign_grade < HIGHEST_GRADE || _exec_grade < HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	if( _sign_grade > LOWEST_GRADE || _exec_grade > LOWEST_GRADE)
		throw Form::GradeTooLowException();
	std::cout << "Initated Form " << name << " with sign_grade = " << sign_grade << " and sign grade = " << _sign_grade << std::endl;
}

Form::Form ( Form const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Form & Form::operator=( Form const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
	{
		this -> name = src.getName();
		this -> is_signed = src.getIsSigned();
		this -> sign_grade = src.getSignGrade();
		this -> exec_grade = src.getExecGrade();
	}
	return *this;
}

// getters
const std::string Form::getName() const
{
	return this -> name;
}

bool Form::getIsSigned() const
{
	return this -> is_signed;
}

const int Form::getSignGrade() const
{
	return this -> sign_grade;
}

const int Form::getExecGrade() const
{
	return this -> exec_grade;
}

// class functionalities
void Form::incGrade(int value)
{
	if (this -> grade - value <= HIGHEST_GRADE)
		throw Form::GradeTooHighException();
	this -> grade -= value;
}

void Form::decGrade(int value)
{
	if (this -> grade + value >= LOWEST_GRADE)
		throw Form::GradeTooLowException();
	this -> grade += value;
}

//exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!";
}

Form::~Form( void )
{
	std::cout << "deleting Form " << name << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Form& B)
{
	os << B.getName() << ", Form grade " << B.getGrade() << std::endl;
	return (os);
}
