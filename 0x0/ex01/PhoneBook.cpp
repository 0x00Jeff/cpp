#include"PhoneBook.class.hpp"
#include<iostream>
#include<sstream>
#include<iomanip>

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
	std::cout << contacts[i].get_first_name().size() << std::endl;;
}

void PhoneBook::debug_view_contact( void )
{
	std::cout << "viewing contact #" << this -> i << std::endl;
	contacts[i].view_info();
	i = ++i % 8;
}

void PhoneBook::search_for_contact( void )
{
	std::stringstream ss;
	std::string choice;
	int index; 

	choice = get_input("Enter index to search : ");
	if (choice.find_first_not_of("-0123456789") != std::string::npos)
	{
		std::cout << "invalid input!" << std::endl;
		return;
	}
	ss << choice;
	ss >> index;
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
};

void Contact::display_column( std::string column )
{
	if (column.size() < 10)
		std::cout << std::setw(10) << column;
	else
		std::cout << column.substr(9) << ".";
}
