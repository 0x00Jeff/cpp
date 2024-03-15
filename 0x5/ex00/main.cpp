#include "Bureaucrat.hpp"

int main(void)
{
	/*
	Bureaucrat aa("jeff", 15);
	Bureaucrat ab;

	std::cout << "before : " << std::endl;
	std::cout << aa;
	std::cout << ab;

	ab = aa;

	std::cout << "after : " << std::endl;
	std::cout << aa;
	std::cout << ab;

	return (0);
	*/
	/*
	// grade too high
	Bureaucrat a;
	try {
		a = Bureaucrat("a", 0);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
	*/
	// grade too low

	/*
	Bureaucrat b;
	try {
		b = Bureaucrat("b", 169);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return(0);
	*/
	// inc exception
	Bureaucrat c("c", HIGHEST_GRADE);
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
		d.decGrade();
		std::cout << d;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
		std::cout << d;
	}
}
