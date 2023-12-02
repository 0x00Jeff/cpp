#include"HumanA.hpp"

HumanA::HumanA( std::string _name, Weapon &w ) : weapon(w), name(_name)
{
	std::cout << "HumanA created with name : " << this -> name << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}

void HumanA::attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
