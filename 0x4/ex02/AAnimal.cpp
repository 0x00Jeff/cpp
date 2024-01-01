#include"AAnimal.hpp"

AAnimal::AAnimal( void ) : type ("default animal type")
{
	std::cout << "default AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal( std::string _type ) : type(_type)
{
	std::cout << "default AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal ( AAnimal const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

AAnimal & AAnimal::operator=( AAnimal const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.getType();
	return *this;
}

const std::string AAnimal::getType( void ) const
{
	return (this -> type);
}

void AAnimal::makeSound( void ) const
{
	std::cout << "default animal sound" << std::endl;
}

AAnimal::~AAnimal( void )
{
	std::cout << "AAnimal Destructor called" << std::endl;
}
