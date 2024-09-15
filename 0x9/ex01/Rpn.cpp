#include"Rpn.hpp"

// constructors
Rpn::Rpn(string &notation)
{
	compileRpnNotation(validateRpnNotation(notation));
	displayCompiledCode();
	//executeCompiledCode();
}

void Rpn::displayCompiledCode()
{
	vector<char>::iterator opIt = s.opcodes.begin();
	vector<char>::iterator opIte = s.opcodes.end();

	for(; opIt < opIte; opIt++)
		displayOperation(opIt);
}

void Rpn::displayOperation(vector<char>::iterator &opIt)
{
	switch(*opIt)
	{
		case ADD_OPCODE: cout << "ADD "; break;
		case SUB_OPCODE: cout << "SUB "; break;
		case MUL_OPCODE: cout << "MUL "; break;
		case DIV_OPCODE: cout << "DIV "; break;
	}
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


	arg1 = s.accumulator;
	// TODO : ask ysf how to refractor this garbage;
	string tmpArg(1, *(++opIt));
	arg2 = atoi(tmpArg.c_str());

	cerr << "[DEBUG] [EXEC] [ARG1] " << arg1 << endl;
	cerr << "[DEBUG] [EXEC] [ARG2] " << arg2 << endl;

	cerr << "[DEBUG] [EXEC] ";
	switch(opcode)
	{
		case ADD_OPCODE:
			cerr << "[ADD] ";
			s.accumulator = arg1 + arg2; break;
		case SUB_OPCODE:
			cerr << "[SUB] ";
			s.accumulator = arg1 - arg2; break;
		case MUL_OPCODE:
			cerr << "[MUL] ";
			s.accumulator = arg1 * arg2; break;
		case DIV_OPCODE:
			cerr << "[DIV] ";
				if (!arg2)
					throw Rpn::Error();
				s.accumulator = arg1 / arg2; break;
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

int Rpn::isValidOperation(char op)
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
		else if(isValidOperation(byte))
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

char Rpn::getNextOperation(vector<string> &tokens, vector<string>::iterator &opIt)
{
	char operation;

	while(opIt != tokens.end() && !isValidOperation((*opIt)[0]))
		opIt++;

	if(opIt == tokens.end())
	{
		cerr << "getNextOperation issue nigga" << endl;
		exit(69);
	}

	operation = (*opIt)[0];
	opIt = tokens.erase(opIt);

	return operation;
}

void Rpn::pushFirstOperand(vector<string> &tokens, vector<string>::iterator &opIt)
{
	s.accumulator = getNextOperand(tokens, opIt);
}

char Rpn::getNextOperand(vector<string> &tokens, vector<string>::iterator &opIt)
{
	char operand;

	opIt--;

	if(opIt == tokens.end())
	{
		cerr << "getNextOperand issue nigga" << endl;
		exit(69);
	}

	operand = (*opIt)[0];
	opIt = tokens.erase(opIt);

	return operand;
}

void Rpn::compileRpnNotation(vector<string> tokens)
{

	//vector<string>::iterator it = tokens.begin()
	vector<string>::iterator opIt = tokens.begin();
	char operand;
	char operation;

	cout << " before special case : tokens.size() = " << tokens.size() << endl;
	pushFirstOperand(tokens, opIt);
	cout << "pushed operand = " << s.accumulator << endl;
	cout << " after special case : tokens.size() = " << tokens.size() << endl;
	s.accumulator = getNextOperand(tokens, opIt);
	while(tokens.size())
	{
		// find operation, erase it, and return its byte
		// and update opIt internally, so we can use it later
		// in getNextOperand
		operation = getNextOperation(tokens, opIt);
		appendOpcodeToByteCode(operation);

		cout << "found operation = " << operation << endl;

		// find operation, erase it, and return its byte
		// and update opIt internally, so we can use it later
		// in getNextOperation
		operand = getNextOperand(tokens, opIt);
		cout << "found operand = " << operand << endl;
		appendOperandToByteCode(operation);

		cout << "tokens.size() = " << tokens.size() << endl;
	}
	appendOperandToByteCode(STOP_OPCODE);
}



// push operations
void Rpn::appendOperationToByteCode(char operation)
{
	// TODO : do we even need this switch any more??
	switch(operation)
	{
		case ADD_OPERATION: appendOpcodeToByteCode(ADD_OPCODE); break;
		case SUB_OPERATION: appendOpcodeToByteCode(SUB_OPCODE); break;
		case MUL_OPERATION: appendOpcodeToByteCode(MUL_OPCODE); break;
		case DIV_OPERATION: appendOpcodeToByteCode(DIV_OPCODE); break;
		default:
			cerr << "[DEBUG] problem in current operation <" << operation << ">" << endl;
			throw Rpn::Error();
	}
}

void Rpn::appendOpcodeToByteCode(int opcode)
{
	appendByteToByteCode(opcode);
}

// unlike appendOpcodeToByteCode, this functions expects ascii representations of the operands
void Rpn::appendOperandToByteCode(char data)
{
	appendByteToByteCode(data);
}

void Rpn::appendByteToByteCode(char byte)
{
	s.opcodes.push_back(byte);
}

int Rpn::getResult()
{
	return s.accumulator;
}

// destructor
Rpn::~Rpn(){}
