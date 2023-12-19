#pragma once

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

		Fixed & operator=( Fixed const & );

		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

		~Fixed( void );
};
