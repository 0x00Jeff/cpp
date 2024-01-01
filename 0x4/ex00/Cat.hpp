#pragma once
#include"Animal.hpp"
#include<iostream>

class Cat : public Animal
{
	protected:
		std::string type;

	public:
		Cat( void );
		Cat ( Cat const & src );

		Cat & operator=( Cat const & );

		virtual void makeSound( void ) const;

		~Cat( void );
};
