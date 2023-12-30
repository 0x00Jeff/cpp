#pragma once
#include"ClapTrap.hpp"
#include<iostream>

class FragTrap : public ClapTrap
{
	private:

	public:

		FragTrap ( void );
		FragTrap ( std::string _name );
		FragTrap ( FragTrap const & src );

		FragTrap & operator=( FragTrap const & src );

		void highFivesGuys(void);

		~FragTrap ();

};
