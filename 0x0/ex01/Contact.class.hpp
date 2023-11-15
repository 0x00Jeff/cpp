#pragma once
#include<iostream>

std::string get_input(std::string prompt);

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		void fill_info( void );
		void view_info( void );
		std::string get_name( void ); // only for debug ?
};
