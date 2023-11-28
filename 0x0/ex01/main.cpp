#include"PhoneBook.class.hpp"
#include<iostream>

std::string get_input(std::string prompt)
{
	std::string input;
	do {
		std::cout << prompt;
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			exit(69);
		}
	} while(input.empty());

	return input;
}


int main(void)
{
	std::string choice;
	PhoneBook phone;

	while (1)
	{
		std::cout << ">>> ";
		std::getline(std::cin, choice);

		if (choice == "ADD")
			phone.add_contact();
		// TODO : FOR DEBUG. DELETE LATER!!
		else if (choice == "VIEW")
			phone.debug_view_contact();
		else if (choice == "SEARCH")
			phone.search_for_contact();
		else if (choice == "EXIT")
			std::exit(69);
		if (std::cin.eof())
			break;
	}
}
