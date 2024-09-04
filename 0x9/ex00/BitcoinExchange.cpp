#include"BitcoinExchange.hpp"

// static members
string BitcoinExchange::btcDbName = "data.csv";
string BitcoinExchange::btcDbHeader = "date,exchange_rate";
string BitcoinExchange::inputFileHeader = "date | value";

vector<string> BitcoinExchange::splitTokensByChar(string &blob, char c)
{
	replace(blob.begin(), blob.end(), c, ' ');
	return BitcoinExchange::splitTokensBySpace(blob);
}

vector<string> BitcoinExchange::splitTokensBySpace(string &blob)
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

bool BitcoinExchange::isValidBtcEntry(string &btcEntry)
{
	vector<string> EntryTokens = BitcoinExchange::splitTokensByChar(btcEntry, ',');
	if (EntryTokens.size() != 2)
		return false;

	string date, price;
	date = EntryTokens[0];
	price = EntryTokens[1];

	return (BitcoinExchange::isValidDate(date) | BitcoinExchange::isValidPrice(price));
}

bool BitcoinExchange::isValidDate(string &dateToken)
{
	string year_tok, month_tok, day_tok;
	int year, month, day;

	vector<string> dateParts = BitcoinExchange::splitTokensByChar(dateToken, '-');
	// date has the 3 parts YYYY-MM-DD
	if (dateParts.size() != 3)
		return false;

	year_tok = dateParts[0];
	month_tok = dateParts[1];
	day_tok = dateParts[2];

	if (year_tok.empty() || month_tok.empty() || day_tok.empty())
		return false;

	// YYYY, MM and DD have to be digits only
	if (year_tok.find_first_not_of("0123456789") != std::string::npos ||
			month_tok.find_first_not_of("0123456789") != std::string::npos ||
			day_tok.find_first_not_of("0123456789") != std::string::npos)
		return false;

	// max digits values, year : 4 digits, month and day are 2 digits max
	if (year_tok.size() > 4 || month_tok.size() > 2 || day_tok.size() > 2)
		return false;

	year = atoi(year_tok.c_str());
	month = atoi(month_tok.c_str());
	day = atoi(day_tok.c_str());

	// actual max values
	// TODO : ask ysf if we can use atoi
	if (year > 2024 || month > 12 || day < 31)
		return false;

	return (true);
}

bool BitcoinExchange::isValidPrice(string &priceToken)
{
	return (BitcoinExchange::isValidFloat(priceToken));
}

bool BitcoinExchange::isValidUnit(string &unitToken)
{
	if (!isValidFloat(unitToken))
		return (false);

	stringstream unitsStream(unitToken);
	float units;
	unitsStream >> units;

	if (units < 0)
		throw BitcoinExchange::nigativeUnit();
	// I'm displaying the date error in a wrong way!!
	return (true);
}

bool BitcoinExchange::isValidFloat(string &priceToken)
{
	if (!priceToken.size())
		return false;

	// delete potential '.'
	size_t pos = priceToken.find('.');
	if (pos != std::string::npos)
		priceToken.erase(pos, 1);

	// check if valid int
	if (priceToken.find_first_not_of("0123456789") != std::string::npos)
		return (false);

	return (true);
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

const char *BitcoinExchange::badFileHeader::what() const throw()
{
	return "Error: bad file header";
}

const char *BitcoinExchange::noUsefulBtcData::what() const throw()
{
	return "Error: no values in the btc database";
}

const char *BitcoinExchange::invalidBtcEntry::what() const throw()
{
	return "Error: malformed btc entry";
}

const char *BitcoinExchange::btcEntryAlreadyExists::what() const throw()
{
	return "Error: duplicated date in the datebase";
}

const char *BitcoinExchange::invalidInputEntry::what() const throw()
{
	return "Error: malformed btc price query";
}

const char *BitcoinExchange::nigativeUnit::what() const throw()
{
	return "Error: not a positive number.";
}

// constructors
BitcoinExchange::BitcoinExchange(string &input)
{
	(void)input; // TODO : deal with this later!!

	registerBitcoinValues();
	displayResults(input);
}

void BitcoinExchange::displayResults(string inputFile)
{

	// TODO : impl
	ifstream inputStream;
   	openFile(inputStream, inputFile);

	string line;

	// input file header
	checkFileHeader(inputStream, BitcoinExchange::inputFileHeader);
	while(getline(inputStream, line))
	{
		try 
		{
			if (!BitcoinExchange::isValidInputEntry(line))
				throw BitcoinExchange::invalidInputEntry();
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}

		displayResult(line);
	}
}

bool BitcoinExchange::isValidInputEntry(string &btcEntry)
{
	vector<string> EntryTokens = BitcoinExchange::splitTokensByChar(btcEntry, '|');
	if (EntryTokens.size() != 2)
		return false;

	string date, units;
	date = EntryTokens[0];
	units = EntryTokens[1];

	return (BitcoinExchange::isValidDate(date) | BitcoinExchange::isValidUnit(units));
}

void BitcoinExchange::displayResult(string inputEntry)
{
	vector<string> inputEntryParts = BitcoinExchange::splitTokensByChar(inputEntry, '|');
	string date = inputEntryParts[0];
	float units;

	stringstream unitsStream(inputEntryParts[1]);
	unitsStream >> units;

	map<string, float>::iterator it = btcDb.upper_bound(date);
	if (it != btcDb.begin())
		it--;

	float price = it -> second;

	cout << endl << "searching for : " << date << endl;
	cout << "date : " << it -> first << endl;
	cout << "price: " << price << endl;
	cout << "units: " << units << endl;

	cout << it -> first << " => " << units << std::fixed << setprecision(1) << units * price << endl;
}

// class methods
void BitcoinExchange::registerBitcoinValues(void)
{
	vector<btcEntry> btcEntries;
	ifstream databaseStream;
   	openFile(databaseStream, BitcoinExchange::btcDbName);
	parseBtcEntries(databaseStream, btcEntries);
	databaseStream.close();
}


void BitcoinExchange::parseBtcEntries(ifstream &databaseStream, vector<btcEntry> &btcEntries)
{
	// TODO : remove this struct
	(void) btcEntries;
	int lines;
	string line;

	// database header
	checkFileHeader(databaseStream, BitcoinExchange::btcDbHeader);

	lines = 0;
	while(getline(databaseStream, line))
	{
		if (!BitcoinExchange::isValidBtcEntry(line))
			throw BitcoinExchange::invalidBtcEntry();
		registerBitcoinPriceEntry(line);

		lines++;
	}
	// TODO : remove the following line later
	cout << "there were " << lines << " lines in the dabase" << endl;
	if (!lines)
		throw BitcoinExchange::noUsefulBtcData();
}

void BitcoinExchange::registerBitcoinPriceEntry(string btcEntry)
{
	string date;
	float price;
	vector<string> btcEntryParts = BitcoinExchange::splitTokensByChar(btcEntry, ',');
	date = btcEntryParts[0];
	stringstream priceStream(btcEntryParts[1]);
	priceStream >> price;

	if (btcDb.find(date) != btcDb.end())
		throw BitcoinExchange::btcEntryAlreadyExists();

	btcDb[date] = price;
}

// TODO : make the exceptions generic
void BitcoinExchange::checkFileHeader(ifstream &databaseStream, string &fileHeader)
{
	string line;

	if (!getline(databaseStream, line))
		throw BitcoinExchange::EmptyBtcDb();

	if (line != fileHeader)
		throw BitcoinExchange::badFileHeader();
}

void BitcoinExchange::openFile(ifstream &databaseStream, string &dbName)
{
	databaseStream.open(dbName.c_str(), std::ifstream::in);
	if (!databaseStream.is_open())
		throw BitcoinExchange::cannotOpenBitcoinDatabase();
}

// destructor
// TODO : maybe clear the map??
BitcoinExchange::~BitcoinExchange(){}
