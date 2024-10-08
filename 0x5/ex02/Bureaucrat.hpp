#pragma once
#include<iostream>
#include<stdexcept>
#include"AForm.hpp"
#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class AForm;
class Bureaucrat
{

	protected:
		const std::string name;
		int	grade;

	public:
		Bureaucrat( void );
		Bureaucrat( std::string _name, int _grade );
		Bureaucrat ( Bureaucrat const & src );

		Bureaucrat & operator=( Bureaucrat const & );

		// getters
		std::string getName() const;
		int getGrade() const;
		// class functionalities
		void incGrade( int value = 1 );
		void decGrade( int value = 1 );
		void signForm(std::string fname, bool success );
		void executeForm(AForm const & form);

		// exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		~Bureaucrat( void );
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& B);
