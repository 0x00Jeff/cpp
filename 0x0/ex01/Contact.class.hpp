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
		std::string get_first_name( void );
		std::string get_last_name( void );
		std::string get_nickname( void );
		std::string get_phone_number( void );
		std::string get_darkest_secret( void );

		void set_first_name( std::string Fname );

		void fill_info( void );
		void view_info( void );
		std::string get_name( void ); // only for debug ?
};
