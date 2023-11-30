#include"PhoneBook.hpp"
#include<iostream>

PhoneBook::PhoneBook( void ) : index(0) {}

void PhoneBook::add_contact( void )
{
	std::cout << "adding a new contact to index " << this -> index << std::endl;
	contacts[index].fill_info();
	index = (index + 1) % 8;
}

void PhoneBook::search_for_contact( void )
{
	int index;

	display_contacts();
	do {
		index = get_number("Enter index to search : ");
		if (index < 0 || index > 7)
			std::cout << "index out of range!" << std::endl;
	} while (index < 0 || index > 7);
	contacts[index].display_contact_info();
}

void PhoneBook::display_contacts( void )
{
	int index;

	index = 0;
	while (index < 8)
	{
		contacts[index].display_contact_preview(index);
		index++;
	}
}
