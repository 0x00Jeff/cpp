#pragma once
#include<sstream>
#include<iostream>
#include<stack>
#include<vector>
#include<cstdlib>

using std::string;
using std::vector;
using std::stack;

using std::ifstream;
using std::stringstream;

using std::cout;
using std::cerr;
using std::endl;

using std::atoi;

#define MAKE_FIRST_OPCODE(x) (x | (1 << 4))
#define IS_FIRST_OPCODE(x) (x >> 4)
#define GET_OP(x) (x & 7)

enum BYTECODE
{
	ADD_OPCODE = 0,
	SUB_OPCODE,
	MUL_OPCODE,
	DIV_OPCODE,
	STOP_OPCODE
};

enum OPERATIONS
{
	ADD_OPERATION = '+',
	SUB_OPERATION = '-',
	MUL_OPERATION = '*',
	DIV_OPERATION = '/'
};

struct state
{
	vector<char> opcodes;
	stack<int> stack;
	size_t rip;
};

class Rpn
{
	private:
		// constructors
		Rpn(Rpn &ref);
		Rpn &operator=(Rpn &ref);

		state s;

		// exceptions
		class Error : public std::exception
		{
			virtual const char *what() const throw();
		};

		// static functions
		static int isNumber(char c);
		static int isValidOperand(char c);
		static int isValidOpcode(char c);
		static vector<string> splitTokensBySpace(string &tokens);

		// private class funcationalities
		// validaiton
		vector<string> validateRpnNotation(string &notation);

		// DEBUG
		void printIteratorGroup(vector<string> &tokens, vector<string>::iterator &curr);

		// compilatipon
		void compileRpnNotation(vector<string> tokens);
		void displayCompiledCode();
		void displayOperation(vector<char>::iterator &opIt);

		// execution
		void executeCompiledCode();
		void execSingleOpcode(vector<char>::iterator &opIt);

		// bytecode operations
		void appendToByteCode(char data);

		// stack operations
		void appendByteToByteCode(char byte);
		void appendOperationToByteCode(char operation, bool firstOperation);
		void appendOpcodeToByteCode(char opcode, bool firstOpcode);
		void appendOperandToByteCode(char data);
		void pushOpcode(char data);
		void pushOperand(char data);
		char getNextOperand(vector<string> &opcodes, vector<string>::iterator &currOpcodeIt);

		//
		void pushData(char data);

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
