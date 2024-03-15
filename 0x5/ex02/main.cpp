#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat b("j", 5);
		ShrubberyCreationForm Shrub("Shrub");
		Shrub.beSigned(b);
		Shrub.execute(b);

		RobotomyRequestForm Robot("Robot");
		Robot.beSigned(b);
		Robot.execute(b);
		Robot.execute(b);

		PresidentialPardonForm	Pres("Pres");
		Pres.beSigned(b);
		Pres.execute(b);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
