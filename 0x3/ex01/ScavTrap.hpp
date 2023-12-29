#pragma once
#include"ClapTrap.hpp"
#include<iostream>

class ScavTrap : public ClapTrap
{
	private:

	public:

	ScavTrap ( std::string _name );

	void attack(const std::string& target);
	void guardGate();

	~ScavTrap ();

};
