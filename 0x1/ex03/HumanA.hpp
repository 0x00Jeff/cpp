#pragma once
#include"Weapon.hpp"
#include<iostream>

class HumanA
{
	private:
		Weapon &weapon;
		std::string name;
	public:
		HumanA( Weapon &w );
		~HumanA();
		void attack();
};
