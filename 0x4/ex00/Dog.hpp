#pragma once
#include"Animal.hpp"
#include<iostream>

class Dog : public Animal
{
	protected:
		std::string type;

	public:
		Dog( void );
		Dog ( Dog const & src );

		Dog & operator=( Dog const & );

		virtual void makeSound( void ) const;

		~Dog( void );
};
