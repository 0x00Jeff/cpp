/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 14:31:59 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 15:02:10 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern( void )
{
	std::cout << "Initiated an Intern " << std::endl;
}

Intern::Intern ( Intern const & src )
{
	*this = src;
}

Intern & Intern::operator=( Intern const & src)
{
	(void)src;
	return (*this);
}

// getters

// class functionalities
AForm *Intern::makeShrubberyForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresedentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	unsigned int index;
	std::string choices[] = {"robotomy request",
	   							"shrubbery creation",
								"presidential pardon",
								""};
	func_ptr ptrs[] = {&Intern::makeRobotomyRequestForm,
							&Intern::makeShrubberyForm,
							&Intern::makePresedentialPardonForm};
	index = 0;
	while (!choices[index].empty() && choices[index] != formName)
		index++;
	if (index > 2)
		throw Intern::Invalid_Form_Name();
	return (this->*(ptrs[index]))(formTarget);
}

const char *Intern::Invalid_Form_Name::what() const throw()
{
	return "Invalid Form name!";
}

Intern::~Intern( void )
{
	std::cout << "deleting Intern" << std::endl;
}
