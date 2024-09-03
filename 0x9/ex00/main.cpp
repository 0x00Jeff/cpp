#include"BitcoinExchange.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Error: could not open file." << endl;
		return (-1);
	}

	try
	{
		string inputFile(argv[1]);
		BitcoinExchange btc(inputFile);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (-1);
	}
}
