#pragma once
#include<iostream>

class WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongAnimal( void );
		WrongAnimal( std::string _type );
		WrongAnimal ( WrongAnimal const & src );

		WrongAnimal & operator=( WrongAnimal const & );

		const std::string getType( void ) const;
		void makeSound( void ) const;

		virtual ~WrongAnimal( void );
};
