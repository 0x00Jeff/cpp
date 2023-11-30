#pragma once
#include<iostream>
#include"Contact.hpp"

int get_number( std::string prompt );

class PhoneBook
{
private:
	int index;
		Contact contacts[8];
	public:
		PhoneBook( void );
		void add_contact( void );
		void debug_view_contact( void );
		void search_for_contact( void );
		void display_contacts( void );
};
