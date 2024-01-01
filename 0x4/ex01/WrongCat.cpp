#include"WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat")
{
	std::cout << "default WrongCat Constructor called" << std::endl;
}

WrongCat::WrongCat ( WrongCat const & src ) : WrongAnimal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	//*this = src;
}

WrongCat & WrongCat::operator=( WrongCat const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.type;
	return *this;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat sounds" << std::endl;
}

WrongCat::~WrongCat( void )
{
	std::cout << "Destructor called" << std::endl;
}
