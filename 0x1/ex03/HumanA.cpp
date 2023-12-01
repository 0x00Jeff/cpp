#include"HumanA.hpp"

HumanA::HumanA( Weapon &w ) : weapon(w)
{
	std::cout << "HumanA created" << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA destroyed" << std::endl;
}

void HumanA::attack( void )
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}
