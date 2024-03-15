/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:40:50 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 12:45:11 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

const int ShrubberyCreationForm::sign_grade = 145;
const int ShrubberyCreationForm::exec_grade = 137;

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", sign_grade, exec_grade)
{
	std::cout << "Initiated default ShrubberyCreationForm " << this -> getName() << " with sign grade = " << this -> getSignGrade() << " and an exec grade is " << this -> getExecGrade() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string _target ) : AForm("ShrubberyCreationForm", sign_grade, exec_grade), target(_target)
{
	std::cout << "Initiated ShrubberyCreationForm " << this -> getName() << " with sign_grade = " <<  getSignGrade() << " and exec grade = " << getExecGrade() << " and target = " << target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm ( ShrubberyCreationForm const & src ) : AForm(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & src)
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
std::string ShrubberyCreationForm::getTarget() const
{
	return this -> target;
}

// class functionalities : inhereted
void ShrubberyCreationForm::do_action() const
{
	std::string fname = target;
	std::ofstream outfile;
	fname += "_shrubbery";
	outfile.open(fname.c_str(), std::ofstream::out);
	if (!outfile.is_open())
		throw FileCannotBeOppened();
	for (int i = 0; i < 69; i++)
	{
		outfile <<
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
	}
	outfile.close();
}

// exceptions
const char *ShrubberyCreationForm::FileCannotBeOppened::what() const throw()
{
	return "Cannot open file";
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "deleting ShrubberyCreationForm " << this -> getName() << std::endl;
}
