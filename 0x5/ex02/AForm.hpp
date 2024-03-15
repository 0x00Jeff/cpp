/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:30:42 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/14 17:00:26 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:14:24 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/14 16:28:46 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"
#include<iostream>
#include<stdexcept>
#define HIGHEST_GRADE	1
#define LOWEST_GRADE	150

class AForm
{
	private:
		const std::string name;
		bool is_signed;
		const int sign_grade;
		const int exec_grade;

	public:

		AForm( void );
		AForm( std::string _name, int _sign_grade, int _exec_grade );
		AForm ( AForm const & src );

		AForm & operator=( AForm const & );

		// getters
		const std::string getName() const;
		bool getIsSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		// class functionalities
		void beSigned(Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		void virtual do_action() const = 0;

		// exceptions
		class GradeTooHighException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class Cannot_Exec_Action : public std::exception
		{
			virtual const char *what() const throw();
		};

		~AForm( void );
};

std::ostream& operator<<(std::ostream& os, const AForm& B);
