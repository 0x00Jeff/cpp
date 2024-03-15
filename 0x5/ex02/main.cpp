#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try {
		Bureaucrat b("jeff", 5);
		PresidentialPardonForm PForm("Shrub");
		PForm.beSigned(b);
		PForm.execute(b);
		PForm.execute(b);
		PForm.execute(b);
	//	Shrub.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
