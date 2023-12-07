#include"ClapTrap.hpp"

ClapTrap::ClapTrap()
{
}

ClapTrap::ClapTrap( std::string _name ) : hit_points(10), energy_points(10), attack_damage(0)
{
	name = _name;
	std::cout << "ClapTrap created with name " << name << "!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this -> energy_points <= 0)
		return;
	this -> energy_points--;
	std::cout << "ClapTrap " << name << " attacks " << target << " , causing " << this -> attack_damage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this -> hit_points -= amount;
	if (this -> hit_points)
		this -> hit_points = 0;
	std::cout << this -> name << " took " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this -> energy_points <= 0)
		return;
	this -> energy_points--;
	this -> hit_points += amount;
	std::cout << this -> name << " repaired " << amount << " points!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}
