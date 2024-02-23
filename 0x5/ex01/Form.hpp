#pragma once
#include<iostream>
#include<stdexcept>
#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class Form
{
	private:
		const std::string name;
		bool is_signed = false;
		int sign_grade;
		int exec_grade;

	public:

		Form( void );
		Form( std::string _name, int _sign_grade, int _exec_grade );
		Form ( Form const & src );

		Form & operator=( Form const & );

		// getters
		const std::string getName() const;
		bool getIsSigned() const;
		const int getSignGrade() const;
		const int getExecGrade() const;
		// class functionalities
		void incGrade(int value = 1);
		void decGrade(int value = 1);

		// exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};

		~Form( void );
};

std::ostream& operator<<(std::ostream& os, const Form& B);
