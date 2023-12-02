#pragma once
#include"Weapon.hpp"
#include<iostream>

class HumanB
{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB( std::string _name );
		~HumanB();
		void attack();
		void setWeapon( Weapon &weapon );
};
