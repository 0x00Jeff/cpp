#include"WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type ("wrong default animal type")
{
	std::cout << "default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string _type ) : type(_type)
{
	std::cout << "default WrongAnimal Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal ( WrongAnimal const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.type;
	return *this;
}

const std::string WrongAnimal::getType( void ) const
{
	return (this -> type);
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "default animal sound" << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "Destructor called" << std::endl;
}
