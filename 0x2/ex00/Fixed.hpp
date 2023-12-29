#pragma once

class Fixed
{
	private:
		int n;
		static const int fbits;
	public:
		Fixed( void );
		Fixed( int _n );
		Fixed( Fixed const & );

		Fixed & operator=( Fixed const & );

		int getRawBits( void ) const;
		void setRawBits( int const raw );

		~Fixed( void );
};
