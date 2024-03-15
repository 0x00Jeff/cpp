#pragma once
#include "AForm.hpp"
#include<iostream>
#include<stdexcept>

class ShrubberyCreationForm : public AForm
{
	private:
		static const int sign_grade;
		static const int exec_grade;
		std::string target;

	public:

		ShrubberyCreationForm( void );
		ShrubberyCreationForm( std::string _name );
		ShrubberyCreationForm ( ShrubberyCreationForm const & src );
		ShrubberyCreationForm & operator=( ShrubberyCreationForm const & );

		// getters
		std::string getTarget() const;
		// exceptions
		class FileCannotBeOppened : public std::exception
		{
			virtual const char *what() const throw();
		};
		// class functionalities : inhereted
		virtual void do_action() const;
		// exceptions : inhereted

		~ShrubberyCreationForm( void );
};

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& B);
