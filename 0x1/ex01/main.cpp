#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(void)
{
	int i;
	Zombie *hord;
	int N = 5;

	hord = zombieHorde(N, "jeffy");
	if (!hord)
		return (0);
	i = 0;
	while (i < N)
		hord[i++].annouce();
	i = 0;
	delete [] hord;
}
