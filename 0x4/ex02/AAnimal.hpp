#pragma once
#include<iostream>

class AAnimal
{
	protected:
		std::string type;

	public:
		AAnimal( void );
		AAnimal( std::string _type );
		AAnimal ( AAnimal const & src );

		AAnimal & operator=( AAnimal const & );

		const std::string getType( void ) const;
		virtual void makeSound( void ) const = 0;

		virtual ~AAnimal( void );
};
