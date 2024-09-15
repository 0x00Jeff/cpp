#include"Rpn.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		cerr << "Usage : " << argv[0] << " [Rpn]" << endl;
		return (-1);
	}

	try
	{
		string notation(argv[1]);
		Rpn rpn(notation);
		cout << rpn.getResult() << endl;
	} catch (std::exception &e)
	{
		cerr << e.what() << endl;
		return (-1);
	}

	return (0);
}
