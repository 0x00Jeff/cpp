#include"Rpn.hpp"

// constructors
Rpn::Rpn(string &notation)
{
	compileRpnNotation(validateRpnNotation(notation));
	displayCompiledCode();
}

void Rpn::displayCompiledCode()
{
	vector<char>::iterator opIt = s.opcodes.begin();
	vector<char>::iterator opIte = s.opcodes.end();

	for(; opIt != opIte; opIt++)
	{
	//	cout << *opIt << " " << endl;
		displayOperation(opIt);
	}
}

void Rpn::displayOperation(vector<char>::iterator &opIt)
{
	static bool first = true;
//	cout << "operation = " << *opIt << endl;
//	cout << "operation = " << GET_OP(*opIt) << endl;
	switch(GET_OP(*opIt))
	{
		case ADD_OPCODE: cout << "ADD "; break;
		case SUB_OPCODE: cout << "SUB "; break;
		case MUL_OPCODE: cout << "MUL "; break;
		case DIV_OPCODE: cout << "DIV "; break;
	}
	if (first)
	{
		cout << *(++opIt) << " ";
		cout << *(++opIt) << endl;
		first = false;
	}
	else
		cout << *(++opIt) << endl;
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

int Rpn::isValidOperand(char c)
{
	return isNumber(c);
}

int Rpn::isValidOpcode(char op)
{
	return (op == ADD_OPERATION \
			|| op == SUB_OPERATION\
			|| op == MUL_OPERATION \
			|| op == DIV_OPERATION);
}

vector<string> Rpn::splitTokensBySpace(string &blob)
{
	string tmpToken;
	string tmpTmpToken;
	vector<string> tokens;
	stringstream ss(blob);

	if (!blob.size())
		return tokens;

	while(ss >> tmpToken)
		tokens.push_back(tmpToken);

	return tokens;
}

// private class funcationalities
vector<string> Rpn::validateRpnNotation(string &notation)
{
	vector<string> tokens = splitTokensBySpace(notation);
	cout << notation << endl;
	if (!tokens.size())
		throw Rpn::Error();

	vector<string>::iterator it = tokens.begin();
	vector<string>::iterator ite = tokens.end();

	// TODO : use this?
	//size_t opcodesCount = 0;
	size_t operandsCount = 0;
	char byte;

	while(it != ite)
	{
		if ((*it).size() != 1)
		{			cerr << "[DEBUG] operator/operand too long <" << *it << ">" << endl;
			throw Rpn::Error();
		}

		byte = (*it)[0];
//		cout << "[DEBUG] byte = " << byte << endl;

		if (isValidOperand(byte))
				operandsCount++;
		else if(isValidOpcode(byte))
		{
			if (operandsCount < 2)
			{
				cerr << "[DEBUG] not enough operands for operator" << endl;
				throw Rpn::Error();
			}
			operandsCount--;
		}
		else
		{
			cerr << "[DEBUG] invalid opcode or operand <" << byte << ">" << endl;
			throw Rpn::Error();
		}

		it++;
	}

	if (operandsCount != 1)
	{
		cerr << "[DEBUG] unused operands in notation" << endl;
		throw Rpn::Error();
	}

	return tokens;
}

void Rpn::compileRpnNotation(vector<string> tokens)
{
	vector<string>::iterator it = tokens.begin();
	vector<string>::iterator ite = tokens.end();

	bool firstOpcode = true;

	while(it != ite)
	{
		char byte = (*it)[0];
		char tmpByte;

		if (isValidOpcode(byte))
		{
			if (firstOpcode)
			{
				cerr << "[DEBUG] [COMPILE] [OPCODE] appending <" << byte << ">, firstOpcode = " << firstOpcode << endl;
				appendOperationToByteCode(byte, firstOpcode);
				
				tmpByte = (*getNextOperand(tokens))[0];
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> to bytecode" << endl;
				appendOperandToByteCode(tmpByte);

				tmpByte = (*getNextOperand(tokens))[0];
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> to bytecode" << endl << endl;
				appendOperandToByteCode(tmpByte);
				firstOpcode = false;
			}
			else
			{
				cerr << "[DEBUG] [COMPILE] [OPCODE] appending <" << byte << ">, firstOpcode = " << firstOpcode << endl;
				appendOperationToByteCode(byte, firstOpcode);
				tmpByte = (*getNextOperand(tokens))[0];
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> " << endl << endl;
				appendOperandToByteCode(tmpByte);
			}
		}
		it++;
	}
}

vector<string>::iterator Rpn::getNextOperand(vector<string> &opcodes)
{
	static vector<string>::iterator it = opcodes.end();
	static vector<string>::iterator ite;
	vector<string>::iterator nextOperand = opcodes.end();

	int byte;

	if (it == opcodes.end())
		it = opcodes.begin();

	if (ite != opcodes.end())
		ite = opcodes.end();

	while(it != ite)
	{
		byte = (*it)[0];
		it++;
		if (isValidOperand(byte))
		{
			nextOperand = it - 1;
			break;
		}
	}
	if (nextOperand == opcodes.end())
	{
		cerr << "[DEBUG] if you're seeing this then there is a serious bug in your code xd" << endl;
		exit(0);
	}
	return nextOperand;
}

/*
void Rpn::checkAndPush(string &elem)
{
	if (elem.size() > 1)
		throw Rpn::Error();

	char elemChar = elem[0];
	switch (elemChar)
	{
		case '*':
		case '/'
		case '-':
		case '+':
			push_rsp(exec_opcode(elemChar));
			return;
	}

	if (!isValidOperand(elemChar))
		throw Rpn::Error();
	push_rsp(elemChar - '0');
}
*/


/*
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
*/

// push operations
void Rpn::appendOperationToByteCode(char operation, bool firstOperation)
{
	switch(operation)
	{
		case ADD_OPERATION: appendOpcodeToByteCode(ADD_OPCODE, firstOperation); break;
		case SUB_OPERATION: appendOpcodeToByteCode(SUB_OPCODE, firstOperation); break;
		case MUL_OPERATION: appendOpcodeToByteCode(MUL_OPCODE, firstOperation); break;
		case DIV_OPERATION: appendOpcodeToByteCode(DIV_OPCODE, firstOperation); break;
		default:
			cerr << "[DEBUG] problem in current operation <" << operation << ">" << endl;
			throw Rpn::Error();
	}
}

void Rpn::appendOperandToByteCode(char data)
{
	appendByteToByteCode(data);
}

void Rpn::appendOpcodeToByteCode(char opcode, bool firstOpcode)
{
	if (firstOpcode)
		opcode = MAKE_FIRST_OPCODE(opcode);

	appendByteToByteCode(opcode);
}

void Rpn::appendByteToByteCode(char byte)
{
	s.opcodes.push_back(byte);
}


int Rpn::pop_rsp(void)
{
	int stackTop;
	if (!s.stack.size())
		throw Rpn::Error();

	stackTop = s.stack.top();
	s.stack.pop();
	s.rip++;
	return stackTop;
}

void Rpn::push_rsp(int data)
{
	s.stack.push(data);
}

int Rpn::getResult()
{
	if (s.stack.size() != 1)
		throw Rpn::Error();
	return pop_rsp();
}

// destructor
Rpn::~Rpn(){}
