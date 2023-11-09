#pragma once

#include"Contact.class.hpp"

class PhoneBook
{
	private:
		int index;
		Contact contacts[8];
	public:
		PhoneBook( void );
		void add_contact( void );
};
