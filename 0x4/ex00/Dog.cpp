#include"Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
	std::cout << "default Dog Constructor called" << std::endl;
}

Dog::Dog ( Dog const & src ) : Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	//*this = src;
}

Dog & Dog::operator=( Dog const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.type;
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Bark Bark!" << std::endl;
}

Dog::~Dog( void )
{
	std::cout << "Destructor called" << std::endl;
}
