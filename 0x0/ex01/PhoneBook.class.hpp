#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
#endif

#include"Contact.class.hpp"

class PhoneBook
{
	private:
		int index;
	public:
		Contact contacts[8];
		PhoneBook( void );
};
