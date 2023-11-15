#pragma once
#include<iostream>

#include"Contact.class.hpp"

class PhoneBook
{
	private:
		int index;
		int i;
		Contact contacts[8];
		void display_contact( int i );
	public:
		PhoneBook( void );
		void add_contact( void );
		void debug_view_contact( void );
		void search_for_contact( void );
};
