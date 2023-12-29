#include"ClapTrap.hpp"

ClapTrap::ClapTrap ( std::string _name ) : name(_name), hit_points(10), energy_points(10), attack_damage(10)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this -> energy_points == 0)
		return;

	this -> energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (amount > this -> hit_points)
		this -> hit_points = 0;
	else
		this -> hit_points -= amount;

	std::cout << this -> name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this -> energy_points == 0)
		return;
	this -> energy_points--;
	this -> hit_points += amount;

	std::cout << this -> name << " repaired " << amount << " points!" << std::endl;
}
