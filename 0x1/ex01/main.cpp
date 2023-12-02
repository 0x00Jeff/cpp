#include"Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	int i;
	std::string tmp_name;

	if (N <= 0)
		return (NULL);
	Zombie* z = new Zombie[N];
	i = 0;
	while (i < N)
		z[i++].set_name(name);
	return (z);
}

int main(void)
{
	int i;
	Zombie *hord;

	hord = zombieHorde(10, "jeffy");
	if (!hord)
		return (0);
	i = 0;
	while (i < 10)
		hord[i++].annouce();
	i = 0;
	delete [] hord;
}
