#pragma once
#include<iostream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie ( void );
		~Zombie ( void );
		void annouce( void );

		std::string get_name( void );
		void set_name( std::string name );
};
