#include"Rpn.hpp"

// constructors
Rpn::Rpn(string &notation)
{
	compileRpnNotation(validateRpnNotation(notation));
	displayCompiledCode();
	executeCompiledCode();
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

void Rpn::executeCompiledCode()
{
	vector<char>::iterator opIt = s.opcodes.begin();
	vector<char>::iterator opIte = s.opcodes.end();

	for(; opIt != opIte; opIt++)
		execSingleOpcode(opIt);
}

void Rpn::execSingleOpcode(vector<char>::iterator &opIt)
{
	char opcode = *opIt;
	int arg1, arg2;

	if (IS_FIRST_OPCODE(opcode))
	{
		// TODO : ask ysf how to refractor this garbage;
		string tmpArg(1, *(++opIt));
		arg1 = atoi(tmpArg.c_str());
	}
	else 
		arg1 = pop_rsp();

	string tmpArg(1, *(++opIt));
	arg2 = atoi(tmpArg.c_str());

	cerr << "[DEBUG] [EXEC] [ARG1] " << arg1 << endl;
	cerr << "[DEBUG] [EXEC] [ARG2] " << arg2 << endl;

	cerr << "[DEBUG] [EXEC] ";
	switch(GET_OP(opcode))
	{
		case ADD_OPCODE: 
			cerr << "[ADD] ";
			push_rsp(arg1 + arg2); break;
		case SUB_OPCODE:
			cerr << "[SUB] ";
			push_rsp(arg2 - arg1); break;
		case MUL_OPCODE: 
			cerr << "[MUL] ";
			push_rsp(arg1 * arg2); break;
		case DIV_OPCODE:
			cerr << "[DIV] ";
			  if (!arg2)
				  throw Rpn::Error();
			  push_rsp(arg1 / arg2);
	}
}

// DEBUG
void Rpn::printIteratorGroup(vector<string> &tokens, vector<string>::iterator &curr)
{
	vector<string>::iterator it = tokens.begin();
	vector<string>::iterator ite = tokens.end();

	cerr << "[DEBUG] [NOTATION] : ";
	(void)curr;


	while(it != ite)
	{
		if (it == curr)
			cout << "<" << *it << "> ";
		else
			cout << *it << " ";
		it++;
	}

	cout << endl;
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

	bool firstOpcode = true;

	while(it != tokens.end())
	{
		char byte = (*it)[0];
		char tmpByte;

		printIteratorGroup(tokens, it);

		if (isValidOpcode(byte))
		{
			if (firstOpcode)
			{
				cerr << "[DEBUG] [COMPILE] [OPCODE] appending <" << byte << ">, firstOpcode = " << firstOpcode << endl;
				appendOperationToByteCode(byte, firstOpcode);
				// erase the operator
				cerr << "[DEBUG] [COMPILE] [OPCODE] [ERASE] erasing <" << *it << ">, firstOpcode = " << firstOpcode << endl;
				it = tokens.erase(it);

				
				cerr << "[DEBUG] -> [NextOP]" << endl;
				tmpByte = (getNextOperand(tokens, it));
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> to bytecode" << endl;
				appendOperandToByteCode(tmpByte);

				tmpByte = (getNextOperand(tokens, it));
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> to bytecode" << endl << endl;
				appendOperandToByteCode(tmpByte);
				firstOpcode = false;
	//			it = tokens.erase(it);
			}
			else
			{
				cerr << "[DEBUG] [COMPILE] [OPCODE] appending <" << byte << ">, firstOpcode = " << firstOpcode << endl;
				appendOperationToByteCode(byte, firstOpcode);
				tmpByte = getNextOperand(tokens, it);
				cerr << "[DEBUG] [COMPILE] [OPERAND] appending <" << tmpByte << "> " << endl << endl;
				appendOperandToByteCode(tmpByte);
			}
		}
		else 
			it++;
	}
}

char Rpn::getNextOperand(vector<string> &opcodes, vector<string>::iterator &currOpcodeIt)
{
	char operand;
	currOpcodeIt--;
	while(!isValidOperand((*currOpcodeIt)[0]))
		currOpcodeIt--;

	operand = (*currOpcodeIt)[0];
	cerr << "[DEBUG] [COMPILE] [GETNEXTOPCODE] [ERASE] erasing <" << operand << ">" << endl << endl;
	currOpcodeIt = opcodes.erase(currOpcodeIt);

	return operand;
}

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
	cerr << "[DEBUG] [STACK] [POP] " << stackTop << endl;
	return stackTop;
}

void Rpn::push_rsp(int data)
{
	cerr << "[PUSH] " << data << endl << endl;
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
