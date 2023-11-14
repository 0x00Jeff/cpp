#include"PhoneBook.class.hpp"
#include<iostream>

PhoneBook::PhoneBook( void ) : index(0), i(0) {}

void PhoneBook::add_contact( void )
{
	std::cout << "adding a new contact to index " << this -> index << std::endl;
	contacts[index].fill_info();
	index = ++index % 8;
}

void PhoneBook::display_contact( int i )
{
	std::cout << "received index : " << i << std::endl;
	std::cout << contacts[i].get_name().size() << std::endl;;
}

void PhoneBook::view_contact( void )
{
	std::cout << "viewing contact #" << this -> i << std::endl;
	contacts[i].view_info();
	i = ++i % 8;
}
