#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try {
		Bureaucrat b("jeff", 10);
		PresidentialPardonForm PForm("Shrub");
		PForm.beSigned(b);
		b.executeForm(PForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
