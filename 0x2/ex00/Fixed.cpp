#include<iostream>
#include"Fixed.hpp"

const int Fixed::fbits = 8;

Fixed::Fixed( void ) : n(0)
{
	std::cout << "Default constructor called" << std::endl;;
}

Fixed::Fixed( int _n )
{
	n = _n;
	std::cout << "Parameterized constructor called" << std::endl;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed ( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this -> n );
}

void Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	this -> n = raw;
}

Fixed & Fixed::operator=( Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> n = src.getRawBits();

	return *this;
}
