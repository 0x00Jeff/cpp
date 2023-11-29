#include"PhoneBook.class.hpp"
#include<iostream>
#include<iomanip>

PhoneBook::PhoneBook( void ) : index(0) {}

void PhoneBook::add_contact( void )
{
	std::cout << "adding a new contact to index " << this -> index << std::endl;
	contacts[index].fill_info();
	index = (index + 1) % 8;
}

void PhoneBook::display_contact( int i )
{
	std::cout << "received index : " << i << std::endl;
	std::cout << contacts[i].get_first_name().size() << std::endl;;
}

void PhoneBook::search_for_contact( void )
{
	int index;

	index = get_number("Enter index to search : ");
	if (index < 0 || index > 7)
	{
		std::cout << "index out of range!" << std::endl;
		return;
	}
	contacts[index].display_contact(index);
}

void Contact::display_contact( int index )
{
	if (this -> first_name.empty())
	{
		std::cout << "empty contact!" << std::endl;
		return;
	}
	std::cout << std::setw(10) << index << "|";
	display_column(this -> first_name);
	std::cout << "|";
	display_column(this -> last_name);
	std::cout << "|";
	display_column(this -> nickname);
	std::cout << std::endl;
}

void Contact::display_column( std::string column )
{
	if (column.size() < 10)
		std::cout << std::setw(10) << column;
	else
		std::cout << column.substr(0, 9) << ".";
}
