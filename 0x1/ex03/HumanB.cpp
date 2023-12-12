#include"HumanB.hpp"

HumanB::HumanB( std::string _name ) : name(_name)
{
	std::cout << "HumanB created with name : " << this -> name << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB destroyed" << std::endl;
}

void HumanB::attack( void )
{
	std::string w;
	if (this -> weapon)
		w = weapon -> getType();
	else
		w = "[some unkown weapon]";
	std::cout << name << " attacks with their " << w << std::endl;
}

void HumanB::setWeapon( Weapon &_weapon )
{
	this -> weapon = &_weapon;
}
