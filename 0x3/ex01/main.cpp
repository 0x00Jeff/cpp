#include"ClapTrap.hpp"
#include"ScavTrap.hpp"

int main(void)
{
	ClapTrap *ptr = new ScavTrap("jeff");
	delete ptr;
	(void)ptr;
}
