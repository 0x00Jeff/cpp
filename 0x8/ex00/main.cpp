#include"easyfind.hpp"
#include<iostream>
#include<list>
#include<exception>

int main(void)
{
	std::list<int>	l;

	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);

	try 
	{
		easyfind<std::list<int> >(l, 40);
		std::cout << "element found!" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
