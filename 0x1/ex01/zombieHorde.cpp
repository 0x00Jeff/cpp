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
