#include"PmergeMe.hpp"
#include<iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		cerr << "Usage : " << argv[0] << " elem1 elem2 .." << endl;
		return (-1);
	}

	string input;
	int i = 1;

	while (i < argc - 1)
	{
		input += argv[i++];
		input += " ";
	}
	input += argv[i];

	try 
	{
		PmergeMe P(input);
		P.sort();
	}
	catch (std::exception &e)
	{
		cerr << e.what() << endl;
	}
	return (0);
}
