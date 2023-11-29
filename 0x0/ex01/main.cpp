#include"PhoneBook.class.hpp"
#include<iostream>
#include<cstdlib>
#include<sstream>

int is_number( std::string input )
{
	if (input.find_first_not_of("-0123456789") != std::string::npos)
	{
			std::cout << "invalid input!" << std::endl;
			return (1);
	}
	return (0);
}

std::string get_number_string( std::string prompt )
{
	std::string input;
	do {
		input = get_input(prompt);
	} while (is_number(input) != 0);
	return (input);
}

int get_number( std::string prompt )
{
	std::stringstream ss;
	int number;

	ss << get_number_string(prompt);
	ss >> number;
	return (number);
}


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
		else if (choice == "SEARCH")
			phone.search_for_contact();
		else if (choice == "EXIT")
			std::exit(69);
		if (std::cin.eof())
			break;
	}
}
