#include"Contact.class.hpp"

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
	return (this -> nickname);
}

std::string Contact::get_darkest_secret( void )
{
	return (this -> nickname);
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
	this -> set_phone_number(get_input("Phone Number : "));
	this -> set_darkest_secret(get_input("Darkest Secret : "));
}

// TODO : FOR DEBUG, DELETE LATER!!
void Contact::view_info()
{
	std::cout << "first name : " << first_name << std::endl;
	std::cout << "last name : " << last_name << std::endl;
	std::cout << "nickname : " << nickname << std::endl;
	std::cout << "phone_number : " << phone_number << std::endl;
	std::cout << "darkest_secret : " << darkest_secret << std::endl;
}
