#include"Cat.hpp"

Cat::Cat( void ) : AAnimal("Cat")
{
	std::cout << "default Cat Constructor called" << std::endl;
	this -> b = new Brain();
}

Cat::Cat ( Cat const & src ) : AAnimal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	this -> b = new Brain(*(src.getBrain()));
}

Cat & Cat::operator=( Cat const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
	{
		if (this -> b)
			delete b;
		this -> b = new Brain(*(src.getBrain()));
	}
	return *this;
}

void Cat::makeSound( void ) const
{
	std::cout << "Meow" << std::endl;
}

Brain* Cat::getBrain( void ) const
{
	return (this -> b);
}

Cat::~Cat( void )
{
	std::cout << "Cat Destructor called" << std::endl;
	if (this -> b)
		delete (this -> b);
}
