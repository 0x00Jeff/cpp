#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using std::string;
using std::vector;
using std::map;

using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;
using std::stringstream;

class BitcoinExchange
{
	private:
		// constructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &ref);
		BitcoinExchange &operator=(BitcoinExchange &ref);

		// static members
		static string dbName;
		static vector<string> splitBySpace(string blob);

		// class attributes
		map<int, float> db;

		// class methods
		void registerBitcoinValues(void);
		void openDb(ifstream &databaseStream, string dbName);
		void registerBitcoinValuesEntries(ifstream &databaseStream);
		void checkDbHeader(ifstream &databaseStream);

		// exceptions
		class cannotOpenBitcoinDatabase : public std::exception
		{
			virtual const char *what() const throw();
		};

		class EmptyBtcDb : public std::exception
		{
			virtual const char *what() const throw();
		};

		class badBtcDbHeader : public std::exception
		{
			virtual const char *what() const throw();
		};

		class noUsefulBtcData : public std::exception
		{
			virtual const char *what() const throw();
		};

	public:
		// constructors
		BitcoinExchange(string &input);

		// class functionalities
		void addDatabaseEntry();

		// destructor
		~BitcoinExchange();
};
