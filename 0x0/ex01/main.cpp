#include"Contact.class.hpp"
#include"PhoneBook.class.hpp"
#include<iostream>

std::string get_input(std::string prompt)
{
	std::string input;
	std::cout << prompt;
	std::getline(std::cin, input);

	return input;
}


int main(void)
{
	int index;
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
		// TODO : FOR DEBUG. DEBUG, LATER!!
		else if (choice == "VIEW")
		{
			std::cout << "viewing contact .." << std::endl;
			phone.view_contact();
		}
		else if (choice == "SEARCH")
		{
			std::cout << "enter index to search : ";
			std::cin >> index;
	//		phone.display_contact(index);
			//std::cout << "SEARCH" << std::endl;
		}
		else if (choice == "EXIT")
		{
			std::exit(69);
		}
		else
			std::cout << "nah" << std::endl;
		if (std::cin.eof())
		{
			std::cout << "eof received!" << std::endl;
			break;
		}
	}
}
