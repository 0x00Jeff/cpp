#pragma once
#include "AForm.hpp"
#include<iostream>
#include<stdexcept>

class PresidentialPardonForm : public AForm
{
	private:
		static const int sign_grade;
		static const int exec_grade;
		std::string target;

	public:

		PresidentialPardonForm( void );
		PresidentialPardonForm( std::string _name );
		PresidentialPardonForm ( PresidentialPardonForm const & src );

		PresidentialPardonForm & operator=( PresidentialPardonForm const & );

		// getters
		std::string getTarget() const;
		// exceptions : inhereted
		// class functionalities
		virtual void do_action() const;

		// exceptions

		~PresidentialPardonForm( void );
};
