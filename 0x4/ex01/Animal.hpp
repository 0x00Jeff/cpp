#pragma once
#include<iostream>

class Animal
{
	protected:
		std::string type;

	public:
		Animal( void );
		Animal( std::string _type );
		Animal ( Animal const & src );

		Animal & operator=( Animal const & );

		const std::string getType( void ) const;
		virtual void makeSound( void ) const;

		virtual ~Animal( void );
};
