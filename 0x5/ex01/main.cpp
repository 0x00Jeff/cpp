#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b("jeff", 80);
	Form f("F", 70, 20);
	f.beSigned(b);
}
