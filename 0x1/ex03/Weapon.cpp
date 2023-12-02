#include"Weapon.hpp"

Weapon::Weapon( std::string _type ) : type(_type)
{
	std::cout << "Weapon created with type : " << this -> type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon destroyed!" << std::endl;
}

const std::string &Weapon::getType()
{
	return this -> type;
}

void Weapon::setType( std::string _type )
{
	this -> type = _type;
}
