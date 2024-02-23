#include "Bureaucrat.hpp"

int main(void)
{
	// grade too high
	Bureaucrat a;
	try {
		a = Bureaucrat("a", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << a;
	}

	// grade too low

	Bureaucrat b;
	try {
		b = Bureaucrat("b", 169);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << b;
	}

	// inc exception
	Bureaucrat c("c", 1);
	try {
		c.incGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << c;
	}

	// dec exception
	Bureaucrat d("d", LOWEST_GRADE);
	try {
		d.incGrade();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << d;
	}
}
