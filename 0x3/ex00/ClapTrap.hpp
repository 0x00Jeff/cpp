#pragma once
#include<iostream>


class ClapTrap
{
	private:
		std::string		name;
		unsigned int	hit_points;
		int				energy_points;
		int				attack_damage;

	public:
		ClapTrap ( std::string _name );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		~ClapTrap ();
};
