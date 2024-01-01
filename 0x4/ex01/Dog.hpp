#pragma once
#include"Animal.hpp"
#include"Brain.hpp"
#include<iostream>

class Dog : public Animal
{
	private:
		Brain *b;

	public:
		Dog( void );
		Dog ( Dog const & src );

		Dog & operator=( Dog const & );

		virtual void makeSound( void ) const;
		Brain *getBrain( void ) const;

		~Dog( void );
};
