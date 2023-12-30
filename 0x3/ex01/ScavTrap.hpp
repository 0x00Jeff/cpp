#pragma once
#include"ClapTrap.hpp"
#include<iostream>

class ScavTrap : public ClapTrap
{
	private:

	public:

		ScavTrap ( void );
		ScavTrap ( std::string _name );
		ScavTrap ( ScavTrap const & src );

		ScavTrap & operator=( ScavTrap const & src );

		void attack(const std::string& target);
		void guardGate();

		~ScavTrap ();

};
