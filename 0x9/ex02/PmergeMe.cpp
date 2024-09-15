#include"PmergeMe.hpp"

// contructor
PmergeMe::PmergeMe(string input)
{
	parseInput(input);
}

void PmergeMe::sort()
{
	recursiveSort(inputVec, 0, inputVec.size(), 0);
	displayContainerContent(inputVec);
}

void PmergeMe::recursiveSort(vector<int> &c, size_t start, size_t size, int iter)
{
	int i = 0;
	cout << " " ;
	while(i++ < iter)
		cout << " ";
	cout << "called with start = " << start << ", and size = " << size << endl;
	if (size > 5)
	{
		size_t newSize = size >> 1;
		recursiveSort(c, start, newSize, iter + 1);
		recursiveSort(c, start + newSize, newSize + (size % 2), iter + 1);
	}
	else
		binaryInsertionSort(c, start, size);
}

void PmergeMe::binaryInsertionSort(vector<int> &c, size_t start, size_t size)
{
	size_t current_index = 0;
	int curr_number;
	vector<int> tmp;

	tmp.push_back(c[start + current_index++]);

	while(current_index < size)
	{
		curr_number = c[start + current_index++];
		vector<int>::iterator it = lower_bound(tmp.begin(), tmp.end(), curr_number);
		tmp.insert(it, curr_number);
	}

	current_index = start;
	cout << "overwriting from " << start << " to " << start + size << endl;
	size_t i = 0;
	while(i < size)
	{
		c[current_index++] = tmp[i++];
	}
}

/*
void PmergeMe::splitInputIntoPairs()
{
	size_t size = inputList.size();
	size_t i = 0;

	list<int>::iterator it = inputList.begin();

	while( i < size >> 1 )
	{
		int firstElem = *it++;
		int secondElem = *it++;

		inputListPairs.push_back(make_pair(firstElem, secondElem));
		inputDeqPairs.push_back(make_pair(firstElem, secondElem));
		i++;
	}

	if (size % 2)
		leftOver = *it;
}
*/

// exceptions
const char *PmergeMe::invalidNumber::what() const throw()
{
	return "invalid positive number";
}

const char *PmergeMe::emptyContainerPop::what() const throw()
{
	return "you can't pop from an empty container!";
}

// static methods
/*
template <typename Container>
int pop(Container c)
{
	if (!c.size())
		throw PmergeMe::emptyContainerPop();

	int top = c.back();
	c.pop_back();
	return top;
}
*/

// class functionalities
void PmergeMe::parseInput(string input)
{
	stringstream inputStream(input);
	int inputElem;

	// TODO : detect overflow
	while(inputStream >> inputElem)
	{
		if (inputElem < 0)
			throw PmergeMe::invalidNumber();
		inputVec.push_back(inputElem);
		inputDeq.push_back(inputElem);
	}

	if (inputStream.fail() && !inputStream.eof())
		throw PmergeMe::invalidNumber();
}

template <class Container>
void PmergeMe::displayContainerContent(Container &c)
{
	typename Container::iterator it = c.begin();
	typename Container::iterator ite = c.end();

	while(it != ite)
		cout << *it++ << " ";
	cout << endl;
}

/*
template <class Container>
void PmergeMe::displayPairContainerContent(Container &c)
{
	typename Container::iterator it = c.begin();
	typename Container::iterator ite = c.end();

	size_t size = inputList.size();

	cout << "- ";

	while(it != ite)
	{
		cout << "{" << it -> first << ", " << it -> second << "} ";
		it++;
	}

	if (size % 2)
		cout << "{" << leftOver << "}";

	cout << endl;
}
*/

// destructor
PmergeMe::~PmergeMe() { }
