#include"PhoneBook.class.hpp"
#include<iostream>

PhoneBook::PhoneBook( void ) : index(0) {}

void PhoneBook::add_contact( void )
{
	std::cout << "adding a new contact to index " << this -> index << std::endl;
	this -> index++;
}
