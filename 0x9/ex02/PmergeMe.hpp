#include<iostream>
#include<exception>
#include<sstream>
#include<vector>

#include<list>
#include<deque>

using std::vector;
using std::deque;
using std::pair;

using std::string;
using std::stringstream;

using std::make_pair;
using std::cout;
using std::cerr;
using std::endl;

class PmergeMe 
{
	private:
		vector<int> inputVec;

		deque<int> inputDeq;

		//int leftOver;

		// exceptions
		class invalidNumber : public std::exception
		{
			virtual const char *what() const throw();
		};


		// static methods
		template <typename Container>
		int pop(Container c);


		// class functionalities
		void parseInput(string input);
		void recursiveSort(vector<int> &c, size_t start, size_t size, int iter);
		void binaryInsertionSort(vector<int> &c, size_t start, size_t size);

		template <typename Container>
		void displayContainerContent(Container &c);

//		template <class Container>
//		void splitInputIntoPairs(Container c);

//		template <typename Container>
//		void displayPairContainerContent(Container &c);


	public:
		// constructor
		PmergeMe(string input);

		// exception
		class emptyContainerPop : public std::exception
		{
			virtual const char *what() const throw();
		};

		// class functionalities
		void sort(void);

		// destructor
		~PmergeMe();
};
