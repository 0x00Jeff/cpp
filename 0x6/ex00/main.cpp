#include"ScalarConverter.hpp"
#include<iostream>

int main(int argc, char *argv[])
{
	t_types t;
	t.valid = false;
	t.special_case = SPECIAL_CASE_NONE;

	std::string input;
	if (argc != 2)
	{
		std::cerr << "Usage : ./ScalarConverter input" << std::endl;
		return (1);
	}

	input = argv[1];

	try
	{
		ScalarConverter::typeDetector(input, t);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (1);
	}

	ScalarConverter::typeDisplayer(t);
	return (0);
}
