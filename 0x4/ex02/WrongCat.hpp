#pragma once
#include"WrongAnimal.hpp"
#include<iostream>

class WrongCat : public WrongAnimal
{
	protected:
		std::string type;

	public:
		WrongCat( void );
		WrongCat ( WrongCat const & src );

		WrongCat & operator=( WrongCat const & );
		void makeSound( void ) const;

		~WrongCat( void );
};
