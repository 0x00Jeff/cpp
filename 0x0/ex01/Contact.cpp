#include"Contact.class.hpp"

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
