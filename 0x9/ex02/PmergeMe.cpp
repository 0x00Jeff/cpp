#include"PmergeMe.hpp"

// contructor
PmergeMe::PmergeMe(string input)
{
	parseInput(input);
}

void PmergeMe::sort()
{
	clock_t t = clock();
	recursiveSort(inputVec, 0, inputVec.size(), 0);
	displayContainerContent(inputVec);
	t = clock() - t;
	cout << "std::vector took " << ((double)t / 1000) << " ms" << endl;
	//
	clock_t t2 = clock();
	recursiveSort(inputDeq, 0, inputDeq.size(), 0);
	displayContainerContent(inputVec);
	t2 = clock() - t2;
	cout << "std::deque took " << ((double)t2 / 1000) << " ms" << endl;
}

template <typename CONTAINER>
void PmergeMe::recursiveSort(CONTAINER &c, size_t start, size_t size, int iter)
{
	if (size > 25)
	{
		size_t newSize = size >> 1;
		recursiveSort(c, start, newSize, iter + 1);
		recursiveSort(c, start + newSize, newSize + (size % 2), iter + 1);
		mergeSort(c, start, newSize, start + newSize, newSize + (size % 2));
	}
	else
		binaryInsertionSort(c, start, size);
}

template <typename CONTAINER>
void PmergeMe::mergeSort(CONTAINER &c, size_t start1, size_t size1, size_t start2, size_t size2)
{
	vector<int> tmp;

	size_t i1 = start1;
	size_t i2 = start2;
	size_t max1 = start1 + size1;
	size_t max2 = start2 + size2;

	while(i1 < max1 && i2 < max2)
	{
		if (c[i1] < c[i2])
			tmp.push_back(c[i1++]);
		else
			tmp.push_back(c[i2++]);
	}

	if (i1 != max1)
	{
		while(i1 < max1)
			tmp.push_back(c[i1++]);
	}
	else if (i2 != max2)
	{
		while(i2 < max2)
			tmp.push_back(c[i2++]);
	}

	size_t i = 0;
	while(i < size1 + size2)
	{
		c[start1 + i] = tmp[i];
		i++;
	}
}

template <typename CONTAINER>
void PmergeMe::binaryInsertionSort(CONTAINER &c, size_t start, size_t size)
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
	size_t i = 0;
	while(i < size)
		c[current_index++] = tmp[i++];
}

// exceptions
const char *PmergeMe::invalidNumber::what() const throw()
{
	return "invalid positive number";
}

const char *PmergeMe::emptyContainerPop::what() const throw()
{
	return "you can't pop from an empty container!";
}

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

template <typename CONTAINER>
void PmergeMe::displayContainerContent(CONTAINER &c)
{
	typename CONTAINER::iterator it = c.begin();
	typename CONTAINER::iterator ite = c.end();

	while(it != ite)
		cout << *it++ << " ";
	cout << endl;
}

// destructor
PmergeMe::~PmergeMe() { }
