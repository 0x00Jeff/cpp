#pragma once
#include<sstream>
#include<iostream>
#include<stack>

using std::stack;

using std::ifstream;
using std::stringstream;

using std::cout;
using std::cerr;
using std::endl;

class Rpn
{
	private:
		// constructors
		Rpn(Rpn &ref);
		Rpn &operator=(Rpn &ref);

		// class attributes
		stack<int> s;

		// exceptions
		class emptyStack : public std::exception
		{
			virtual const char *what() const throw();
		};

		// private class funcationalities
		int pop_rsp(void);

	public:
		// constructors
		Rpn();

		// public class funcationalities

		// destructor
		~Rpn();
};
