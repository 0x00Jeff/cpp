#include"Rpn.hpp"

// constructors
Rpn::Rpn(string &notation)
{
	parseNotation(notation);
}

const char *Rpn::Error::what() const throw()
{
	return "Error";
}

// static functions
int Rpn::isNumber(char c)
{
	return (c >= '0' && c <= '9');
}

// private class funcationalities
void Rpn::parseNotation(string &notation)
{
	stringstream notationStream(notation);
	string notationElem;

	while(notationStream >> notationElem)
		checkAndPush(notationElem);
}

void Rpn::checkAndPush(string &elem)
{
	if (elem.size() > 1)
		throw Rpn::Error();

	char elemChar = elem[0];
	switch (elemChar)
	{
		case '*':
		case '/':
		case '-':
		case '+':
			push_rsp(exec_opcode(elemChar));
			return;
	}

	if (!isNumber(elemChar))
		throw Rpn::Error();
	push_rsp(elemChar - '0');
}

int Rpn::exec_opcode(char opcode)
{
	int arg1 = pop_rsp();
	int arg2 = pop_rsp();
	int res;
	switch(opcode)
	{
		case '+': res = arg2 + arg1; break;
		case '-': res = arg2 - arg1; break;
		case '*': res = arg2 * arg1; break;
		case '/':
			  if (!arg1)
				  throw Rpn::Error();
			  res = arg2 / arg1;
	}
	return (res);
}

void Rpn::push_rsp(int data)
{
	s.push(data);
}

int Rpn::pop_rsp(void)
{
	int stackTop;
	if (!s.size())
		throw Rpn::Error();

	stackTop = s.top();
	s.pop();
	return stackTop;
}

int Rpn::getResult()
{
	if (s.size() != 1)
		throw Rpn::Error();
	return pop_rsp();
}

// destructor
Rpn::~Rpn(){}
