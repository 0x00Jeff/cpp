#pragma once
#include<iostream>

class Brain
{
	protected:
		std::string ideas[100];

	public:
		Brain( void );
		Brain ( Brain const & src );

		Brain & operator=( Brain const & );

		virtual ~Brain( void );
};
