#include"Contact.class.hpp"
#include"PhoneBook.class.hpp"
#include<iostream>


int main(void)
{
	std::string choice;
	PhoneBook phone;
	
	while (1)
	{
		std::cout << ">>> ";
		std::getline(std::cin, choice);

		if (choice == "ADD")
		{
			std::cout << "adding contact .." << std::endl;
			phone.add_contact();
		}
		else if (choice == "SEARCH")
		{
			std::cout << "SEARCH" << std::endl;
		}
		else if (choice == "EXIT")
		{
			std::exit(69);
		}
		else
			std::cout << "nah" << std::endl;
	}
}
