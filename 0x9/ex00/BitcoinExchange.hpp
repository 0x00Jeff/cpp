#pragma once
#include<iostream>
#include<map>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<iomanip>
#include<cstdlib>

using std::string;
using std::vector;
using std::map;

using std::cout;
using std::cerr;
using std::endl;

using std::ifstream;
using std::stringstream;

using std::atoi;
using std::setprecision;

struct btcEntry
{
	float price;
	int year;
	int month;
	int day;
};

class BitcoinExchange
{
	private:
		// constructors
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange &ref);
		BitcoinExchange &operator=(BitcoinExchange &ref);

		// static members
		static string btcDbName;
		static string btcDbHeader;
		static string inputFileHeader;

		static vector<string> splitTokensByChar(string &blob, char c);
		static vector<string> splitTokensBySpace(string &blob);

		static void openFile(ifstream &databaseStream, string &dbName);
		static void checkFileHeader(ifstream &databaseStream, string &fileHeader);
		static bool isValidBtcEntry(string &btcEntry);
		static bool isValidInputEntry(string &btcEntry);
		static bool isValidDate(string &dateToken);
		static bool isValidPrice(string &priceToken);
		static bool isValidFloat(string &priceToken);
		static bool isValidUnit(string &unitToken);

		// class attributes
		map<string, float> btcDb;

		// class methods
		void registerBitcoinValues(void);
		void parseBtcEntries(ifstream &databaseStream, vector<btcEntry> &btcEntries);
		void registerBitcoinPriceEntry(string btcEntry);

		void displayResults(string inputFile);
		void displayResult(string inputEntry);


		// exceptions
		class cannotOpenBitcoinDatabase : public std::exception
		{
			virtual const char *what() const throw();
		};

		class EmptyBtcDb : public std::exception
		{
			virtual const char *what() const throw();
		};

		class badFileHeader : public std::exception
		{
			virtual const char *what() const throw();
		};

		class noUsefulBtcData : public std::exception
		{
			virtual const char *what() const throw();
		};

		class invalidBtcEntry : public std::exception
		{
			virtual const char *what() const throw();
		};

		class btcEntryAlreadyExists : public std::exception
		{
			virtual const char *what() const throw();
		};

		class invalidInputEntry : public std::exception
		{
			virtual const char *what() const throw();
		};

		class nigativeUnit : public std::exception
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
