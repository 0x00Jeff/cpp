#include"Span.hpp"
#include<iostream>
#include<vector>

int main(void)
{
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		/*
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		*/
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return (-1);
	}

//	std::vector<int> v = sp.getVect();

	/*
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	*/

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

	/*
	v = sp.getVect();
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
		std::cout << *i << " ";
	std::cout << std::endl;
	*/
}
