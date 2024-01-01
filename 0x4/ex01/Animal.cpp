#include"Animal.hpp"

Animal::Animal( void ) : type ("default animal type")
{
	std::cout << "default Animal Constructor called" << std::endl;
}

Animal::Animal( std::string _type ) : type(_type)
{
	std::cout << "default Animal Constructor called" << std::endl;
}

Animal::Animal ( Animal const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Animal & Animal::operator=( Animal const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.getType();
	return *this;
}

const std::string Animal::getType( void ) const
{
	return (this -> type);
}

void Animal::makeSound( void ) const
{
	std::cout << "default animal sound" << std::endl;
}

Animal::~Animal( void )
{
	std::cout << "Animal Destructor called" << std::endl;
}
