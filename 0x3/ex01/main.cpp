#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("jeff");
	scav.attack("the corrector");
	scav.guardGate();
}
