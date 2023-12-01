#include"HumanB.hpp"

HumanB::HumanB( Weapon *w )
{
	this -> weapon = w;
	std::cout << "HumanB created" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
}

void HumanB::attack( void )
{
	std::cout << name << " attacks with their " << weapon -> getType() << std::endl;
}
