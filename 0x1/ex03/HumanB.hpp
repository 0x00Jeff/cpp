#pragma once
#include"Weapon.hpp"
#include<iostream>

class HumanB
{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB();
		~HumanB();
		void attack();
};
