#include"Rpn.hpp"

// constructors
Rpn::Rpn(){}


const char *Rpn::emptyStack::what() const throw()
{
	return "empty stack!";
}


// private class funcationalities
int Rpn::pop_rsp(void)
{
	int stackTop;
	if (s.size())
		throw Rpn::emptyStack();

	stackTop = s.top();
	s.pop();
	return stackTop;
}





// public class funcationalities



// destructor
Rpn::~Rpn(){}
