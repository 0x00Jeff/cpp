#include"ScavTrap.hpp"

ScavTrap::ScavTrap ( std::string _name ) : ClapTrap(_name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this -> energy_points == 0)
		return;

	this -> energy_points--;
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}
