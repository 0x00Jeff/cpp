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
	std::cout << name << " attacks with their " << weapon -> getType() << std::endl;
}

void HumanB::setWeapon( Weapon &_weapon ) 
{
	this -> weapon = &_weapon;
}
