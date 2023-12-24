#include"Fixed.hpp"
#include<iostream>

const int Fixed::fbits = 8;

Fixed::Fixed( void ) : n(0)
{
	std::cout << "Default constructor called" << std::endl;;
}

Fixed::Fixed( const int _n )
{
	std::cout << "Int constructor called" << std::endl;
	this -> n = _n << fbits;
}

Fixed::Fixed( const float fn )
{
	std::cout << "Float constructor called" << std::endl;
	n = roundf(fn * (1 << fbits));
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
	return ( this -> n );
}

void Fixed::setRawBits( int const raw )
{
	this -> n = raw;
}

Fixed & Fixed::operator=( Fixed const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
		this -> n = src.getRawBits();
	return *this;
}

float Fixed::toFloat( void ) const
{
	return ((float)this -> n / (1 << fbits));
}

int Fixed::toInt( void ) const
{
	return ( n >> fbits );
}

std::ostream& operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}

bool Fixed::operator<( const Fixed& f )
{
	return (this -> n < f.getRawBits());
}

bool Fixed::operator<=( const Fixed& f )
{
	return (this -> n <= f.getRawBits());
}

bool Fixed::operator>( const Fixed& f )
{
	return (this -> n > f.getRawBits());
}

bool Fixed::operator>=( const Fixed& f )
{
	return (this -> n >= f.getRawBits());
}

bool Fixed::operator==( const Fixed& f )
{
	return (this -> n == f.getRawBits());
}

bool Fixed::operator!=( const Fixed& f )
{
	return (this -> n ^ f.getRawBits());
}

Fixed& Fixed::min( Fixed& f1, Fixed& f2 )
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed& Fixed::max( Fixed& f1, Fixed& f2 )
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed& Fixed::min( const Fixed &f1, const Fixed &f2 )
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed& Fixed::max( const Fixed&  f1, const Fixed& f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed Fixed::operator +( const Fixed& f )
{
	return Fixed(this -> toFloat() + f.toFloat());
}

Fixed Fixed::operator-( const Fixed& f )
{
	return Fixed(this -> toFloat() - f.toFloat());
}

Fixed Fixed::operator*( const Fixed& f ) const
{
	Fixed point;
	long long res = this -> n * f.n;
	point.setRawBits(res >> fbits);
	return (point);
}


Fixed Fixed::operator/( const Fixed& f ) const
{
	Fixed point;
	long long res = ((this -> n) << fbits) / f.n;
	point.setRawBits(res);
	return (point);
}

Fixed& Fixed::operator++()
{
	++(this -> n);
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed old = *this;
	++(*this);
	return (old);
}
