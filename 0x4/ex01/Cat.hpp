#pragma once
#include"Animal.hpp"
#include"Brain.hpp"
#include<iostream>

class Cat : public Animal
{
	private:
		Brain *b;

	public:
		Cat( void );
		Cat ( Cat const & src );

		Cat & operator=( Cat const & );

		virtual void makeSound( void ) const;
		Brain *getBrain( void ) const;

		~Cat( void );
};
