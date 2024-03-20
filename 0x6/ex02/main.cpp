#include"Base.hpp"
#include<ctime>

Base *generate( void )
{
	Base * instance = NULL;

	srand(time(0));
	switch (rand() & 0b11)
	{
		case 0: std::cout << "returning A " << std::endl ; instance = new A; break;
		case 1: std::cout << "returning B " << std::endl ; instance = new B; break;
		case 2 : case 3: std::cout << "returning C " << std::endl ; instance = new C; break;
	}
	return instance;
}

int main()
{
	Base *b = generate();
	delete b;
}
