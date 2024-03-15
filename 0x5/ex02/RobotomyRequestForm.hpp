/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:59:22 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/15 12:38:37 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include<iostream>
#include<stdexcept>

class RobotomyRequestForm : public AForm
{
	private:
		static const int sign_grade;
		static const int exec_grade;
		std::string target;

	public:

		RobotomyRequestForm( void );
		RobotomyRequestForm( std::string _name );
		RobotomyRequestForm ( RobotomyRequestForm const & src );

		RobotomyRequestForm & operator=( RobotomyRequestForm const & );

		// getters
		std::string getTarget() const;
		// exceptions : inhereted
		// class functionalities
		virtual void do_action() const;

		// exceptions

		~RobotomyRequestForm( void );
};
