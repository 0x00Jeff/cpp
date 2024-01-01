#include"Brain.hpp"

Brain::Brain( void )
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Brainy brain";
	std::cout << "default Brain Constructor called" << std::endl;
}

Brain::Brain ( Brain const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Brain & Brain::operator=( Brain const & src)
{
	if ( this != &src)
	{
		for(int i = 0; i < 100; i++)
			this -> ideas[i] = src.ideas[i];
	}

	std::cout << "Copy assignment operator called" << std::endl;

	return *this;
}

Brain::~Brain( void )
{
	std::cout << "Brain Destructor called" << std::endl;
}
