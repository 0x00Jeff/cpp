/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:40:50 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 15:00:25 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

const int PresidentialPardonForm::sign_grade = 25;
const int PresidentialPardonForm::exec_grade = 5;

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", exec_grade, sign_grade)
{
	std::cout << "Initiated default PresidentialPardonForm " << this -> getName() << " with sign grade = " << this -> getSignGrade() << " and an exec grade is " << this -> getExecGrade() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string _target ) : AForm("PresidentialPardonForm", exec_grade, sign_grade)
{
	target = _target;
	std::cout << "Initated PresidentialPardonForm " << this -> getName() << " with sign_grade = " <<  getSignGrade() << " and exec grade = " << getExecGrade() << " and target = " << target << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm ( PresidentialPardonForm const & src ) : AForm(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & src)
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
std::string PresidentialPardonForm::getTarget() const
{
	return this -> target;
}

// class functionalities
void PresidentialPardonForm::do_action() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "deleting PresidentialPardonForm " << this -> getName() << std::endl;
}
