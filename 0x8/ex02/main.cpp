#include"MutantStack.tpp"

#define _USING_LIST

#ifdef _USING_LIST
#include<list>
	using std::list;
	#define push		push_back
	#define pop			pop_back
	#define STACK		list<int>
#else
	#define STACK		MutantStack<int>
#endif

int main()
{
	STACK mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << *mstack.begin() << std::endl;
	//std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	//MutantStack<int>::iterator it = mstack.begin();
	//MutantStack<int>::iterator ite = mstack.end();
	STACK::iterator it = mstack.begin();
	STACK::iterator ite= mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	//std::stack<int> s(mstack);
	STACK s(mstack);
	return 0;
}
