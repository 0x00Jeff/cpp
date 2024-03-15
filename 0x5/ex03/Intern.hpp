#pragma once
#include<iostream>
#include<stdexcept>
#include"AForm.hpp"

class Intern
{
	public:
		Intern( void );
		Intern( std::string _name, int _grade );
		Intern ( Intern const & src );

		Intern & operator=( Intern const & );

		// getters : not needed
		// class functionalities
		AForm *makeShrubberyForm(std::string target);
		AForm *makeRobotomyRequestForm(std::string target);
		AForm *makePresedentialPardonForm(std::string target);
		AForm *makeForm(std::string formName, std::string formTarget);
		// exceptions
		class Invalid_Form_Name : public std::exception
		{
			virtual const char *what() const throw();
		};


		~Intern( void );
};

typedef AForm* (Intern::*func_ptr)(std::string);
