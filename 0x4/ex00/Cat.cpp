#include"Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
	std::cout << "default Cat Constructor called" << std::endl;
}

Cat::Cat ( Cat const & src ) : Animal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	//*this = src;
}

Cat & Cat::operator=( Cat const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> type = src.type;
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}

Cat::~Cat( void )
{
	std::cout << "Destructor called" << std::endl;
}
