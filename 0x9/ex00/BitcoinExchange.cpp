#include"BitcoinExchange.hpp"

// static members
string BitcoinExchange::dbName = "data.csv";

vector<string> BitcoinExchange::splitBySpace(string blob)
{
	string tmpToken;
	vector<string> tokens;
	stringstream ss(blob);

	if (!blob.size())
		return tokens;

	while(ss >> tmpToken)
		tokens.push_back(tmpToken);

	return tokens;
}

// exceptions
const char *BitcoinExchange::cannotOpenBitcoinDatabase::what() const throw()
{
	return "Error: cannot open data.csv";
}

const char *BitcoinExchange::EmptyBtcDb::what() const throw()
{
	return "Error: btc database cannot be empty";
}

const char *BitcoinExchange::badBtcDbHeader::what() const throw()
{
	return "Error: bad btc database header";
}

const char *BitcoinExchange::noUsefulBtcData::what() const throw()
{
	return "Error: no values in the btc database";
}

// constructors
BitcoinExchange::BitcoinExchange(string &input)
{
	(void)input; // TODO : deal with this later!!

	registerBitcoinValues();
}

// class methods
void BitcoinExchange::registerBitcoinValues(void)
{
	ifstream databaseStream;
   	openDb(databaseStream, BitcoinExchange::dbName);
	registerBitcoinValuesEntries(databaseStream);
	databaseStream.close();
}

void BitcoinExchange::registerBitcoinValuesEntries(ifstream &databaseStream)
{
	int lines;
	string line;

	// database header
	checkDbHeader(databaseStream);
	return;

	lines = 0;
	while(getline(databaseStream, line))
	{
		lines++;
	//	cout << line << endl;
	}
	cout << "there were " << lines << " lines in the dabase" << endl;
//	if (!lines)
//		throw BitcoinExchange::EmptyBtcDb();
}

void BitcoinExchange::checkDbHeader(ifstream &databaseStream)
{
	string line;

	if (!getline(databaseStream, line))
		throw BitcoinExchange::EmptyBtcDb();

	if (line != "date,exchange_rate")
		throw BitcoinExchange::badBtcDbHeader();
}

void BitcoinExchange::openDb(ifstream &databaseStream, string dbName)
{
	databaseStream.open(dbName.c_str(), std::ifstream::in);
	if (!databaseStream.is_open())
		throw BitcoinExchange::cannotOpenBitcoinDatabase();
}



// destructor
// TODO : maybe clear the map??
BitcoinExchange::~BitcoinExchange(){}
