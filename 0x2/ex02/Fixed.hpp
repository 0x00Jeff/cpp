#pragma once
#include<iostream>
#include<sstream>

class Fixed
{
	private:
		int n;
		static const int fbits;
	public:
		Fixed( void );
		Fixed( const int _in );
		Fixed( const float fn );
		Fixed( Fixed const & );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed & operator=( Fixed const & );
		bool operator<( const Fixed& f );
		bool operator<=( const Fixed& f );
		bool operator>( const Fixed& f );
		bool operator>=( const Fixed& f );
		bool operator==( const Fixed& f );
		bool operator!=( const Fixed& f );

		Fixed& operator+( const Fixed& f );
		Fixed& operator-( const Fixed& f );
		Fixed& operator*( const Fixed& f );
		Fixed& operator/( const Fixed& f );

		static Fixed& min( Fixed &f1, Fixed f2);
		static const Fixed& min( Fixed const &f1, Fixed const f2);

		static Fixed& max( Fixed &f1, Fixed f2);
		static const Fixed& max( Fixed const &f1, Fixed const f2);

		~Fixed( void );
};

std::ostream& operator<<(std::ostream& os, const Fixed& f);
