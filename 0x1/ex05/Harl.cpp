#include"Harl.hpp"

Harl::Harl() 
{
	std::cout << "Harl created!" << std::endl;
}

Harl::~Harl() 
{
	std::cout << "Harl destroyed!" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "[DEBUG] : I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "[INFO] : I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[WARNING] : I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ERROR] : This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level )
{
	unsigned int index;
	std::string choices[] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	func_ptr ptrs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	index = 0;
	while (!choices[index].empty() && choices[index] != level)
		index++;

	switch (index)
	{
		case 0 ... 3:
			std::cout << "good level" << std::endl;
			break;
		default:
			std::cout << "bad level" << std::endl;
			break;
	}
}
