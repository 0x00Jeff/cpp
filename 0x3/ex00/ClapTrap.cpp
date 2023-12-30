#include"ClapTrap.hpp"

ClapTrap::ClapTrap () : name("default"), hit_points(10), energy_points(10), attack_damage(10)
{
	std::cout << "ClapTrap default created!" << std::endl;
}

ClapTrap::ClapTrap ( std::string _name ) : name(_name), hit_points(10), energy_points(10), attack_damage(10)
{
	std::cout << "ClapTrap " << name << " created!" << std::endl;
}

ClapTrap::ClapTrap ( ClapTrap const & src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

ClapTrap & ClapTrap::operator=( ClapTrap const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src )
	{
		this -> name = src.name;
		this -> hit_points = src.hit_points;
		this -> energy_points = src.energy_points;
		this -> attack_damage = src.attack_damage;
	}
	return (*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (this -> energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " cannot attack " << target << ", as they don't have enough energy points!" << std::endl;
		return;
	}

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
	{
		std::cout << this -> name << " cannot be repaired as he doesn't have enugh energy points!" << std::endl;
		return;
	}
	this -> energy_points--;
	this -> hit_points += amount;

	std::cout << this -> name << " repaired " << amount << " points!" << std::endl;
}

ClapTrap::~ClapTrap ()
{
	std::cout << "ClapTrap " << name << " destroyed!" << std::endl;
}
