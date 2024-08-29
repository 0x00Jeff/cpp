#include<iostream>
#include<stack>

using std::cout;
using std::endl;

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
	MutantStack();

	MutantStack(MutantStack &ref);
	MutantStack &operator=(MutantStack &ref);

	~MutantStack(){}
//	iterator begin()
//	{
//	}
};
