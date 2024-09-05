#include<iostream>
#include<stack>

using std::cout;
using std::endl;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack()
	{
		cout << "MutantStack created" << endl;
	};

	MutantStack(MutantStack &ref)
	{
		*this = ref;
	}

	MutantStack &operator=(MutantStack &ref)
	{
		if ( this != &ref )
			this -> c = ref.c;
		return (*this);
	}
	
	typedef typename std::deque<T>::iterator iterator;

	iterator begin()
	{
		return this -> c.begin();
	}

	iterator end()
	{
		return this -> c.end();
	}

	~MutantStack()
	{
		cout << "MutantStack destructed" << endl;
	}
};
