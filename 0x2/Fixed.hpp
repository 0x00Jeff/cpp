#pragma once

class Fixed
{
	private:
		int n;
		static const int fbits;
	public:
		Fixed( int _n );
		~Fixed( void );
};
