#pragma once
#include<iostream>

enum 
{
	DEFAULT = -1,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL_CASE_NONE,
	SPECIAL_CASE_NAN,
	SPECIAL_CASE_POS,
	SPECIAL_CASE_NIG
};

typedef struct s_types 
{
	bool valid;
	union
	{
		char c;
		int d;
		float f;
		double ff;
		double placeholder;
	} value;
	int special_case;
} t_types;


class ScalarConverter
{
	private:
		ScalarConverter( void );
		ScalarConverter( ScalarConverter const & src );

		ScalarConverter & operator=( ScalarConverter const & );

		~ScalarConverter( void );
	public:
		// class functionalities : detection
		void static typeDetector(std::string, t_types &t);
		void static isChar(std::string, t_types &t);
		void static isInt(std::string, t_types &t);
		void static isDouble(std::string, t_types &t);
		void static isFloat(std::string, t_types &t);

		// class functionalities : display
		void static typeDisplayer(t_types &t);
		void static displayChar(char c, int special_case);
		void static displayInt(int d, int special_case);
		void static displayFloat(float f, int special_case);
		void static displayDouble(double ff, int special_case);

		// exceptions
		class InvalidChar : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidInt : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidFloat : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidDouble : public std::exception
		{
			virtual const char *what() const throw();
		};

		class InvalidInput : public std::exception
		{
			virtual const char *what() const throw();
		};
};
