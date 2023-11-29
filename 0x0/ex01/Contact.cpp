#include"Contact.class.hpp"
#include<sstream>
#include<iomanip>

std::string Contact::get_first_name( void )
{
	return (this -> first_name);
}

std::string Contact::get_last_name( void )
{
	return (this -> last_name);
}

std::string Contact::get_nickname( void )
{
	return (this -> nickname);
}

std::string Contact::get_phone_number( void )
{
	return (this -> phone_number);
}

std::string Contact::get_darkest_secret( void )
{
	return (this -> darkest_secret);
}

void Contact::set_first_name( std::string fname )
{
	this -> first_name = fname;
}

void Contact::set_last_name( std::string lname )
{
	this -> last_name = lname;
}

void Contact::set_nickname( std::string nick )
{
	this -> nickname = nick;
}

void Contact::set_phone_number( std::string phone )
{
	this -> phone_number = phone;
}

void Contact::set_darkest_secret( std::string secret )
{
	this -> darkest_secret = secret;
}

void Contact::fill_info()
{
	this -> set_first_name(get_input("First name : "));
	this -> set_last_name(get_input("Last name: "));
	this -> set_nickname(get_input("Nickname : "));
	this -> set_phone_number(get_number_string("Phone Number : "));
	this -> set_darkest_secret(get_input("Darkest Secret : "));
}

void Contact::display_contact_preview(int index )
{
	if (this -> first_name.empty())
		return;
	std::cout << std::setw(10) << index << "|";
	display_column(this -> first_name);
	std::cout << "|";
	display_column(this -> last_name);
	std::cout << "|";
	display_column(this -> nickname);
	std::cout << std::endl;
}

void Contact::display_contact_info( void )
{
	if (get_first_name().empty())
	{
		std::cout << "contact is empty!" << std::endl;
		return;
	}
	std::cout << "First name : " << get_first_name() << std::endl;
	std::cout << "Last name : " << get_last_name() << std::endl;
	std::cout << "Nickname : " << get_nickname() << std::endl;
	std::cout << "Phone_number : " << get_phone_number() << std::endl;
	std::cout << "Darkest secret : " << get_darkest_secret() << std::endl;
}

void Contact::display_column( std::string column )
{
	if (column.size() < 10)
		std::cout << std::setw(10) << column;
	else
		std::cout << column.substr(0, 9) << ".";
}
