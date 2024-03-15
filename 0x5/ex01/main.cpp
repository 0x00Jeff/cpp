#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("jeff", 70);
		Form f("F", 70, 20);
		std::cout << f;
		f.beSigned(b);
		std::cout << f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
