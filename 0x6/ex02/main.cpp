#include"Base.hpp"
#include<sys/time.h>

Base *generate( void )
{
	Base * instance = NULL;
	struct timeval t;
	gettimeofday(&t, NULL);

	srand(t.tv_sec + t.tv_usec);
	switch (rand() % 3)
	{
		case 0: std::cout << "returning A " << std::endl ; instance = new A; break;
		case 1: std::cout << "returning B " << std::endl ; instance = new B; break;
		case 2: std::cout << "returning C " << std::endl ; instance = new C; break;
	}
	return instance;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try
	{
		Base& placeholder = dynamic_cast<A&>(p);
		static_cast<void>(placeholder);
		std::cout << "A" << std::endl;
	}
	catch (...){}

	try
	{
		Base& placeholder = dynamic_cast<B&>(p);
		static_cast<void>(placeholder);
		std::cout << "B" << std::endl;
	}
	catch (...){}

	try
	{
		Base& placeholder = dynamic_cast<C&>(p);
		static_cast<void>(placeholder);
		std::cout << "C" << std::endl;
	}
	catch (...){}
}

int main()
{
	Base *b = generate();
	identify(b);
	delete b;
}
