#include<iostream>

int main(void)
{
	std::string str;
	std::string* str_ptr;
	std::string &str_ref = str;

	str = "HI THIS IS BRAIN";
	str_ptr = &str;

	std::cout << std::hex << &str << std::endl;
	std::cout << std::hex << str_ptr << std::endl;
	std::cout << std::hex << &str_ref << std::endl;// TODO : ask youssef about this

	std::cout << std::endl;

	std::cout << str << std::endl;
	std::cout << *str_ptr << std::endl;
	std::cout << str_ref << std::endl;
}
