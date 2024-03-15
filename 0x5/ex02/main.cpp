#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	AForm *f;
	try {
		Intern i;
		f = i.makeForm("shrubbery creation", "lol");
		delete f;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
