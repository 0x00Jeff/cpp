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

void Contact::set_first_name( std::string Fname )
{
	this -> first_name = Fname;
}

void Contact::set_last_name( std::string lname)
{
	this -> last_name = lname;
}

void Contact::fill_info()
{
	first_name = get_input("First name : ");
	last_name = get_input("Last name: ");
	nickname = get_input("Nickname: ");
	phone_number = get_input("phone number : ");
	darkest_secret = get_input ("darkest_secret : ");
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

std::string Contact::get_name( void )
{
	return this -> first_name;
}
