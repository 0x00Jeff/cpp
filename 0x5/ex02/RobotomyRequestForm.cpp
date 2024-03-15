/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:59:37 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 12:42:00 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <ctime>

const int RobotomyRequestForm::sign_grade = 72;
const int RobotomyRequestForm::exec_grade = 45;

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", exec_grade, sign_grade)
{
	std::cout << "Initiated default RobotomyRequestForm " << this -> getName() << " with sign grade = " << this -> getSignGrade() << " and an exec grade is " << this -> getExecGrade() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( std::string _target ) : AForm("RobotomyRequestForm", exec_grade, sign_grade)
{
	target = _target;
	std::cout << "Initiated RobotomyRequestForm " << this -> getName() << " with sign_grade = " <<  getSignGrade() << " and exec grade = " << getExecGrade() << "and target = " << target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm ( RobotomyRequestForm const & src ) : AForm(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		// TODO : need to copy smtg here later
		;
	}
	return *this;
}

// getters
std::string RobotomyRequestForm::getTarget() const
{
	return this -> target;
}

// class functionalities
void RobotomyRequestForm::do_action() const
{
	srand(time(0));
	static int probability = rand();

	if (probability % 2)
		std::cout << target << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
	probability++;
}


RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "deleting RobotomyRequestForm " << this -> getName() << std::endl;
}
