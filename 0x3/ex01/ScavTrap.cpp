#include"ScavTrap.hpp"

ScavTrap::ScavTrap ( void ): ClapTrap("default")
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap ( std::string _name ) : ClapTrap(_name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap " << name << " created!" << std::endl;
}

ScavTrap::ScavTrap ( ScavTrap const & src ) : ClapTrap(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this -> name = src.name;
	this -> hit_points = src.hit_points;
	this -> energy_points = src.energy_points;
	this -> attack_damage = src.attack_damage;
	return (*this);
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

ScavTrap::~ScavTrap ()
{
	std::cout << "ScavTrap " << name << " destroyed!" << std::endl;
}
