#pragma once
#include<sstream>
#include<iostream>
#include<stack>

using std::string;
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
		class Error : public std::exception
		{
			virtual const char *what() const throw();
		};

		// static functions
		static int isNumber(char c);

		// private class funcationalities
		void parseNotation(string &notation);
		void checkAndPush(string &notationElem);
		int exec_opcode(char opcode);
		
		void push_rsp(int data);
		int pop_rsp(void);

	public:
		// constructors
		Rpn(string &notation);

		// public class funcationalities
		int getResult();

		// destructor
		~Rpn();
};
