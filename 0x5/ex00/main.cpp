#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("jeff", LOWEST_GRADE - 1);
	try {
		std::cout << b;
		b.decGrade(10);
		std::cout << b;
		b.decGrade();
		std::cout << b;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
