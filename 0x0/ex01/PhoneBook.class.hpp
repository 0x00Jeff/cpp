#pragma once

#include"Contact.class.hpp"

class PhoneBook
{
	private:
		int index;
		int i;
		Contact contacts[8];
	public:
		PhoneBook( void );
		void add_contact( void );
		void view_contact( void );
};
