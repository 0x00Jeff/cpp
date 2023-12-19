#include"Fixed.hpp"
#include<iostream>
#include<cmath>

int main( void ) {
	Fixed a(5.5f);
	std::cout << a.toInt() << std::endl;
	std::cout << roundf(5.23);
	return 0;
}
